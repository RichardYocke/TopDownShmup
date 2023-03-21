// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "AssaultWeapon.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNSHMUP_API AAssaultWeapon : public AWeapon
{
	GENERATED_BODY()
		AAssaultWeapon();

	virtual void OnStartFire() override;
	virtual void OnStopFire() override;
	float FireRate;
	float WeaponRange = 10000.0f;
	
	UPROPERTY(EditDefaultsOnly)
		UParticleSystem* HitEffect;
	FTimerHandle MemberTimerHandle;
protected:
	void WeaponTrace();
	
};
