			// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIEnemyController.h"
#include "Kismet/GameplayStatics.h"
#include "DwarfCharacter.h"
#include "AIDwarfController.generated.h"


enum class EDwarfState : short
{
	EStart, EChasing, EAttacking, EDead, EUnknown
};

UCLASS()
class TOPDOWNSHMUP_API AAIDwarfController : public AAIEnemyController
{
	GENERATED_BODY()
		
	APawn* MyPawn;
	APawn* PlayerActor;
	ADwarfCharacter* DwarfChar;

	EDwarfState GetCurrentState() const;
	void SetCurrentState(EDwarfState NewState);

	UPROPERTY(EditAnywhere)
		float DwarfRange = 150.0f;

	virtual void OnPossess(APawn* InPawn) override;
	virtual void BeginPlay() override;
	virtual void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result) override;

	virtual void Tick(float DeltaTime) override;

private:
	/*Keeps Track of the current state*/
	EDwarfState CurrentState;
	/*Handle any function calls that rely on changing the play state of our game*/
	void HandleNewState(EDwarfState NewState);
	void MoveDwarf();
	APawn* PlayerActor;

};
