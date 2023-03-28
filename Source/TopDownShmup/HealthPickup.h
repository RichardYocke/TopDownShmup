// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "HealthPickup.generated.h"

UCLASS()
class TOPDOWNSHMUP_API AHealthPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHealthPickup();
	UPROPERTY(EditAnywhere, Category = Mesh)
	UStaticMeshComponent* PlayerMesh;

	UPROPERTY(EditAnywhere)
		USphereComponent* ItemCollision;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
