// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <UE5_Tests/UE5_TestsCharacter.h>
#include <UE5_Tests/UE5_TestsProjectile.h>

#include "BaseWeapon.generated.h"

class USkeletalMeshComponent;
class AUE5_TestsCharacter;
class AUE5_TestsProjectile;

UCLASS()
class UE5_TESTS_API ABaseWeapon : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* WeaponMesh;
	/** Projectile class to spawn */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile)
		TSubclassOf<class AUE5_TestsProjectile> ProjectileClass;
	/** Projectile class to spawn */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile)
		TSubclassOf<class AUE5_TestsProjectile> SecondaryProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		USoundBase* FireSound;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		USoundBase* SecondaryFireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		UAnimMontage* FireAnimation;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		UAnimMontage* SecondaryFireAnimation;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector MuzzleOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay)
		bool isHitscan;
	// Sets default values for this actor's properties
	ABaseWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	AUE5_TestsCharacter* Character;
	UPROPERTY(EditDefaultsOnly, Category = Damage)
		int DamagePrimary;
	UPROPERTY(EditDefaultsOnly, Category = Damage)
		int DamageSecondary;
	UPROPERTY(EditDefaultsOnly, Category = Damage)
		int RateOfFire;

public:
	UFUNCTION(BlueprintImplementableEvent)
		void AfterFireEvent();
	/** Attaches the actor to a FirstPersonCharacter */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void AttachWeapon();

	/** Make the weapon Fire a Projectile */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void Fire();

	/** Make the weapon Fire a Projectile */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void SecondaryFire();

	UFUNCTION(BlueprintImplementableEvent)
		void NiagaraEvent();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
