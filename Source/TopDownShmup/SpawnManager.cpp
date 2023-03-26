// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnManager.h"

// Sets default values
ASpawnManager::ASpawnManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnManager::BeginPlay()
{
	Super::BeginPlay();
    CurrentCount = FMath::RandRange(minSpawnTime, maxSpawnTime);

    GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ASpawnManager::AdvanceTimer, 1.0f, true);
	
}

// Called every frame
void ASpawnManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ASpawnManager::SpawnDwarf()
{
    
     if (DwarfClass)
    {
        UWorld* World = GetWorld();
        if (World)
        {
            FActorSpawnParameters SpawnParams;
            SpawnParams.Owner = this;
            SpawnParams.Instigator = GetInstigator();
            int spawnPointIndex = CurrentCount = FMath::RandRange(0, 3);
            ATargetPoint* location = spawnPoints[spawnPointIndex];
            FVector currentLoc = location->GetActorLocation();
            FRotator Rotation(0.0f, 0.0f, 0.0f);
            // Spawn the Dwarf
            CurrentDwarf = World->SpawnActor<ADwarfCharacter>(DwarfClass, currentLoc, Rotation, SpawnParams);
            CurrentDwarf->SpawnDefaultController();

        }
    }
     GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ASpawnManager::AdvanceTimer, 1.0f, true);
}

// Advances the timer value and text, gets called once ever second
void ASpawnManager::AdvanceTimer()
{
    --CurrentCount;
    if (CurrentCount < 1)
    {
        //We're done counting down, so stop running the timer.
        GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
        CountdownHasFinished();
    }
}



//  The Implementation of CountdownHasFinished which is set by a blueprint in editor 
void ASpawnManager::CountdownHasFinished_Implementation()
{
   CurrentCount = FMath::RandRange(minSpawnTime, maxSpawnTime);
   SpawnDwarf();

}