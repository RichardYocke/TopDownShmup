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
			// TODO: Process death
			// Stop attack animation,
			StopAttack();
			// UnPossess the AI controller,
			this->UnPossessed();
			// Remove the dwarf from the world
			this->Destroy();
		}
	}
	return ActualDamage;
}


void ADwarfCharacter::StartAttack()
{
	
	PlayAnimMontage(AttackAnim);
}

void ADwarfCharacter::StopAttack()
{
	StopAnimMontage();
}