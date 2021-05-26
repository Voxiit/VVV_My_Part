// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerStats.generated.h"

UCLASS()
class PUGET_API APlayerStats : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerStats();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Increment values
	UFUNCTION(BlueprintCallable, Category = "PlayerStats")
		void Reset();

	UFUNCTION(BlueprintCallable, Category = "PlayerStats")
		void IncrementBulletShoot(int Bullets = 1);

	UFUNCTION(BlueprintCallable, Category = "PlayerStats")
		void IncrementMeleeHit();

	UFUNCTION(BlueprintCallable, Category = "PlayerStats")
		void IncrementBonusCollected();

	UFUNCTION(BlueprintCallable, Category = "PlayerStats")
		void IncrementEnemiesKilled();

	UFUNCTION(BlueprintCallable, Category = "PlayerStats")
		void IncrementGrenadesUsed();

	UFUNCTION(BlueprintCallable, Category = "PlayerStats")
		void IncrementSwapUsed();

	UFUNCTION(BlueprintCallable, Category = "PlayerStats")
		void IncrementDamageRecieved(int Damage);

	UFUNCTION(BlueprintCallable, Category = "PlayerStats")
		void Win();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "PlayerStats")
		int BulletShoot = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "PlayerStats")
		int MeleeHit = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "PlayerStats")
		int BonusCollected = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "PlayerStats")
		int EnemiesKilled = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "PlayerStats")
		float GameTime = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "PlayerStats")
		int GrenadesUsed = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "PlayerStats")
		int SwapUsed = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "PlayerStats")
		int DamageRecieved = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "PlayerStats")
		bool PlayerWin = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
