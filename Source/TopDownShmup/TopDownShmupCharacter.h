// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "Weapon.h"
#include "TopDownShmupCharacter.generated.h"

UCLASS(Blueprintable)
class ATopDownShmupCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
	 
	virtual void BeginPlay() override;


public:
	ATopDownShmupCharacter();

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	UPROPERTY(EditAnywhere, Category = Weapon)
		TSubclassOf<AWeapon> WeaponClass;
	UPROPERTY(EditAnywhere)
		float Health = 100.f;
	UPROPERTY(EditDefaultsOnly)
		UAnimMontage* DeathAnim;
	float deathTimer = 0.f;
	FTimerHandle TimerHandle;
	USkeletalMeshComponent* PlayerSkeletalMesh;
	UStaticMeshComponent* PlayerMesh;
	ACharacter* PlayerCharacter;
	

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent,
		AController* EventInstigator, AActor* DamageCauser) override;
	bool alive = true;
	void OnStartFire();
	void OnStopFire();
	bool isDead();
	APlayerController* PlayerController;
private:
	AWeapon* MyWeapon;
	APawn* PlayerActor;

	

};

