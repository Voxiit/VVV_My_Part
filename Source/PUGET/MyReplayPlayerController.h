// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "MyReplayPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PUGET_API AMyReplayPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Replays")
		void RestartRecording();

	UFUNCTION(BlueprintCallable, Category = "Replays")
		void PauseReplay(APlayerState* playerStateReplayController);

	UFUNCTION(BlueprintCallable, Category = "Replays")
		void ResumeReplay();

	UFUNCTION(BlueprintCallable, Category = "Replays")
		void NormalSpeedReplay();

	UFUNCTION(BlueprintCallable, Category = "Replays")
		void IncreaseSpeedReplay();

	UFUNCTION(BlueprintCallable, Category = "Replays")
		void DecreaseSpeedReplay();

	UFUNCTION(BlueprintCallable, Category = "Replays")
		void GoForwardInTime();

	UFUNCTION(BlueprintCallable, Category = "Replays")
		void GoBackwardInTime();

	UFUNCTION(BlueprintCallable, Category = "Replays")
		float GetDemoCurrentTime();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Heatmap")
		float CurrentTime = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Heatmap")
		float TotalTime = 0.0f;

private:
	float CurrentReplaySpeed = 1.0f;

};
