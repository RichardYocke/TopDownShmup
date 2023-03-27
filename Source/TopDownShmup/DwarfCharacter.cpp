// Fill out your copyright notice in the Description page of Project Settings.


#include "DwarfCharacter.h"
#include "AIDwarfController.h"

ADwarfCharacter::ADwarfCharacter()
{
	AIControllerClass = AAIDwarfController::StaticClass();
}

float ADwarfCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent,
	AController* EventInstigator, AActor* DamageCauser)
{
	float ActualDamage = Super::TakeDamage(Damage, DamageEvent,
		EventInstigator, DamageCauser);
	if (ActualDamage > 0.0f)
	{
		//TODO: Add a debug message on screen to know dwarf got hit
		//Reduce health points
		Health -= ActualDamage;
		if (Health <= 0.0f)
		{
			// We're dead
			SetCanBeDamaged(false); // Don't allow further damage

			// Stop attack animation,
			StopAttack();
			// UnPossess the AI controller,
			this->UnPossessed();
			//play death anim
			deathLength = PlayAnimMontage(DeathAnim);
			deathLength -= 0.25f;
			//timer to delay destroy till animation length goes through
			GetWorldTimerManager().SetTimer(TimerHandle, [this]() { this->Destroy(); }, deathLength, false);
			
			this->RemoveFromRoot();
			// Remove the dwarf from the world
			
		}
	}
	return ActualDamage;
}


void ADwarfCharacter::StartAttack()
{
	PlayerActor = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	
	//timer = value for the timer
	//looping timer
	 attackLength = PlayAnimMontage(AttackAnim);
	 
	 GetWorldTimerManager().SetTimer(attackTimer, [this]() { PlayerActor->TakeDamage(damage, FDamageEvent(), GetInstigatorController(), this); }, attackLength, false);
}

void ADwarfCharacter::StopAttack()
{
	if(this){
	StopAnimMontage();
	GetWorldTimerManager().ClearTimer(TimerHandle);
	}
}