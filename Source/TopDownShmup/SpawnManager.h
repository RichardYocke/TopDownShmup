// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/TargetPoint.h"
#include "DwarfCharacter.h"
#include "SpawnManager.generated.h"

UCLASS()
class TOPDOWNSHMUP_API ASpawnManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnManager();
	UPROPERTY(EditAnywhere, Category = "Spawn")
		TArray<ATargetPoint*> spawnPoints;

	UPROPERTY(EditAnywhere, Category = "Spawn")
		TSubclassOf<ACharacter> currentTarget;

	UPROPERTY(EditAnywhere, Category = "Spawn")
		float minSpawnTime = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Spawn")
		float maxSpawnTime = 8.0f;

	float CurrentCount;

	FTimerHandle CountdownTimerHandle;

	UFUNCTION(BlueprintNativeEvent)
		void CountdownHasFinished();
	virtual void CountdownHasFinished_Implementation();


	void AdvanceTimer();

	UPROPERTY(EditAnywhere, Category = "Spawn")
		TSubclassOf<ADwarfCharacter> DwarfClass;

	ADwarfCharacter* CurrentDwarf;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SpawnDwarf();
};
