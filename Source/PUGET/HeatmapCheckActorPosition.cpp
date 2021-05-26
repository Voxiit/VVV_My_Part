// Fill out your copyright notice in the Description page of Project Settings.


#include "HeatmapCheckActorPosition.h"

// Sets default values for this component's properties
UHeatmapCheckActorPosition::UHeatmapCheckActorPosition()
{
	PrimaryComponentTick.bCanEverTick = false;
}


bool UHeatmapCheckActorPosition::CheckPosition(FVector2D PlayerPosition, FVector2D MinPosition, FVector2D MaxPosition)
{
	return MinPosition.X < PlayerPosition.X&& PlayerPosition.X < MaxPosition.X&& MinPosition.Y < PlayerPosition.Y&& PlayerPosition.Y < MaxPosition.Y;
}

