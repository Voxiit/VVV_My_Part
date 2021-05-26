// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Math/Vector2D.h"
#include "Components/ActorComponent.h"
#include "HeatmapCheckActorPosition.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PUGET_API UHeatmapCheckActorPosition : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHeatmapCheckActorPosition();

	UFUNCTION(BlueprintCallable, Category = "Heatmap")
		bool CheckPosition(FVector2D PlayerPosition, FVector2D MinPosition, FVector2D MaxPosition);
};
