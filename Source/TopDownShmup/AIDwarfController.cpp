// Fill out your copyright notice in the Description page of Project Settings.


#include "AIDwarfController.h"

void AAIDwarfController::BeginPlay()
{
	Super::BeginPlay();
	PlayerActor = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	MoveToActor(PlayerActor);
	
}



void AAIDwarfController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	MyPawn = InPawn;
}


void AAIDwarfController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Yellow, FString::Printf(TEXT("move completed")));
}