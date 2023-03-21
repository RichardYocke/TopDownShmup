// Fill out your copyright notice in the Description page of Project Settings.


#include "AssaultWeapon.h"

AAssaultWeapon::AAssaultWeapon()
{
	FireRate = 0.05f;
}




void AAssaultWeapon::OnStartFire()
{
	Super::OnStartFire();
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AAssaultWeapon::WeaponTrace, FireRate, true);
}




void AAssaultWeapon::OnStopFire()
{
	Super::OnStopFire();
	GetWorldTimerManager().ClearTimer(MemberTimerHandle);
}




void AAssaultWeapon::WeaponTrace() 
{
	static FName WeaponFireTag = FName(TEXT("WeaponTrace")); static FName MuzzleSocket = FName(TEXT("MuzzleFlashSocket"));
	// Start from the muzzle's position 
	FVector StartPos = WeaponMesh->GetSocketLocation(MuzzleSocket); 
	// Get forward vector of MyPawn 
	FVector Forward = MyPawn->GetActorForwardVector(); 
	// Calculate end position 
	FVector EndPos = Forward * (StartPos + WeaponRange); /*TODO: Figure out vector math based on the WeaponRange*/;
	// Perform line trace to retrieve hit info 
	FCollisionQueryParams TraceParams(WeaponFireTag, true, GetInstigator());
	// This fires the ray and checks against all objects w/ collision 
	FHitResult Hit(ForceInit); 
	GetWorld()->LineTraceSingleByObjectType(Hit, StartPos, EndPos, FCollisionObjectQueryParams::AllObjects, TraceParams);
		// Did this hit anything? 
	if (Hit.bBlockingHit) 
	{ 
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HitEffect, Hit.ImpactPoint);// TODO: Actually do something 
	}
}