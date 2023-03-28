// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TopDownShmupPlayerController.h"
#include "TopDownShmup.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include <TopDownShmupCharacter.h>

ATopDownShmupPlayerController::ATopDownShmupPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void ATopDownShmupPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

		UpdateMouseLook();
}

void ATopDownShmupPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();


	InputComponent->BindAxis("MoveForward", this, &ATopDownShmupPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ATopDownShmupPlayerController::MoveRight);



	InputComponent->BindAction("Fire", IE_Pressed, this, &ATopDownShmupPlayerController::OnStartFire);
	InputComponent->BindAction("Fire", IE_Released, this, &ATopDownShmupPlayerController::OnStopFire);
}



void ATopDownShmupPlayerController::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		APawn* const Pawn = GetPawn();
		if (Pawn)
		{
			Pawn->AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Value);
		}
	}
}



void ATopDownShmupPlayerController::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		APawn* const Pawn = GetPawn();
		if (Pawn)
		{
			Pawn->AddMovementInput(FVector(0.0f, 1.0f, 0.0f), Value);
		}
	}
}


void ATopDownShmupPlayerController::UpdateMouseLook()
{
	// Trace to see what is under the mouse cursor
	APawn* const Pawn = GetPawn();
	FHitResult Hit;
	//GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Pawn)
	{
		// check on dead
		if (this->IsLookInputIgnored())
		{
			return;
		}
		// We hit something, move there
		//SetNewMoveDestination(Hit.ImpactPoint);
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);
		if (Hit.bBlockingHit)
		{
			// We hit something, move there
			actorRotate = Hit.ImpactPoint - Pawn->GetActorLocation();
			actorRotate.Z = 0.f;
			actorRotate.GetSafeNormal();
			Pawn->SetActorRotation(actorRotate.Rotation());
		}

	}
}




void ATopDownShmupPlayerController::OnStartFire()
{
	APawn* const Pawn = GetPawn();
	if (Pawn)
	{
		ATopDownShmupCharacter* MyCharacter = Cast<ATopDownShmupCharacter>(Pawn);
		MyCharacter->OnStartFire();
	}
}





void ATopDownShmupPlayerController::OnStopFire()
{
	APawn* const Pawn = GetPawn();
	if (Pawn)
	{
		ATopDownShmupCharacter* MyCharacter = Cast<ATopDownShmupCharacter>(Pawn);
		MyCharacter->OnStopFire();
	}
}