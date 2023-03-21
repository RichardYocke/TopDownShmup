// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/PlayerController.h"
#include "TopDownShmupPlayerController.generated.h"

UCLASS()
class ATopDownShmupPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATopDownShmupPlayerController();

protected:
	float value;
	FVector actorRotate;
	void MoveForward(float Value);
	void MoveRight(float Value);
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	
	/*
	 Navigate player to the given world location.
	void SetNewMoveDestination(const FVector DestLocation);
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
	void MoveToMouseCursor();
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);
	*/

	void OnStartFire();
	void OnStopFire();

	//mouse update
	void UpdateMouseLook();
	
};


