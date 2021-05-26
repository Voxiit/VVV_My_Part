// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStats.h"

// Sets default values
APlayerStats::APlayerStats()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void APlayerStats::Tick(float DeltaTime)
{
	GameTime += DeltaTime;
}

void APlayerStats::Reset()
{
	BulletShoot = 0;
	MeleeHit = 0;
	BonusCollected = 0;
	EnemiesKilled = 0;
	GameTime = 0.0f;
	GrenadesUsed = 0;
	SwapUsed = 0;
	DamageRecieved = 0;
	PlayerWin = false;
}

void APlayerStats::IncrementBulletShoot(int Bullets)
{
	BulletShoot += Bullets;
}

void APlayerStats::IncrementMeleeHit()
{
	MeleeHit++;
}

void APlayerStats::IncrementBonusCollected()
{
	BonusCollected++;
}

void APlayerStats::IncrementEnemiesKilled()
{
	EnemiesKilled++;
}

void APlayerStats::IncrementGrenadesUsed()
{
	GrenadesUsed++;
}

void APlayerStats::IncrementSwapUsed()
{
	SwapUsed++;
}

void APlayerStats::IncrementDamageRecieved(int Damage)
{
	DamageRecieved += Damage;
}

void APlayerStats::Win()
{
	PlayerWin = true;
}

// Called when the game starts or when spawned
void APlayerStats::BeginPlay()
{
	Super::BeginPlay();	
}

