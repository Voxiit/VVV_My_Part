// Fill out your copyright notice in the Description page of Project Settings.


#include "MyReplayPlayerController.h"
#include "Engine/World.h"
#include "Engine/DemoNetDriver.h" 
#include "GameFramework/WorldSettings.h"
#include "GameFramework/PlayerState.h"

void AMyReplayPlayerController::RestartRecording()
{
	if (UWorld* World = GetWorld())
	{
		if (UDemoNetDriver* DemoDriver = World->DemoNetDriver)
		{
			DemoDriver->GotoTimeInSeconds(0.f);
			TotalTime = DemoDriver->DemoTotalTime;
		}
	}
}

void AMyReplayPlayerController::PauseReplay(APlayerState* playerStateReplayController)
{
	if (AWorldSettings* WorldSettings = this->GetWorldSettings())
	{
		WorldSettings->SetPauserPlayerState(playerStateReplayController);
	}
}

void AMyReplayPlayerController::ResumeReplay()
{
	if (AWorldSettings* WorldSettings = this->GetWorldSettings())
	{
		WorldSettings->SetPauserPlayerState(nullptr);
	}
}

void AMyReplayPlayerController::NormalSpeedReplay()
{
	if (AWorldSettings* WorldSettings = this->GetWorldSettings())
	{
		CurrentReplaySpeed = 1.0f;
		WorldSettings->DemoPlayTimeDilation = CurrentReplaySpeed;
	}
}

void AMyReplayPlayerController::IncreaseSpeedReplay()
{
	if (AWorldSettings* WorldSettings = this->GetWorldSettings())
	{
		if (CurrentReplaySpeed < 3)
		{
			CurrentReplaySpeed += 0.1f;
		}
		WorldSettings->DemoPlayTimeDilation = CurrentReplaySpeed;
	}
}

void AMyReplayPlayerController::DecreaseSpeedReplay()
{
	if (AWorldSettings* WorldSettings = this->GetWorldSettings())
	{
		if (CurrentReplaySpeed > 0.3)
		{
			CurrentReplaySpeed -= 0.1f;
		}
		WorldSettings->DemoPlayTimeDilation = CurrentReplaySpeed;
	}
}

void AMyReplayPlayerController::GoForwardInTime()
{
	CurrentTime = CurrentTime + 1.0f >= TotalTime ? TotalTime : CurrentTime + 1.0f;
	if (UWorld* World = GetWorld())
	{
		if (UDemoNetDriver* DemoDriver = World->DemoNetDriver)
		{
			DemoDriver->GotoTimeInSeconds(CurrentTime);
		}
	}
}

void AMyReplayPlayerController::GoBackwardInTime()
{
	CurrentTime = CurrentTime - 1.0f <= 0.0f ? 0.0f : CurrentTime - 1.0f;
	if (UWorld* World = GetWorld())
	{
		if (UDemoNetDriver* DemoDriver = World->DemoNetDriver)
		{
			DemoDriver->GotoTimeInSeconds(CurrentTime);
		}
	}
}

float AMyReplayPlayerController::GetDemoCurrentTime()
{
	if (UWorld* World = GetWorld())
	{
		if (UDemoNetDriver* DemoDriver = World->DemoNetDriver)
		{
			return DemoDriver->GetDemoCurrentTime();
		}
	}
	return 0.0f;
}
