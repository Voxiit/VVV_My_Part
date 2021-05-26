// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/TextureRenderTarget2D.h" 
#include "Materials/MaterialInstanceDynamic.h" 
#include "GameFramework/Character.h"
#include "Components/SceneComponent.h" 
#include "Math/Color.h" 
#include "Misc/Paths.h"
#include "Kismet/KismetRenderingLibrary.h" 
#include "Kismet/GameplayStatics.h"
#include "GenericPlatform/GenericPlatformFile.h" 
#include "Heatmap.generated.h"

UCLASS()
class PUGET_API AHeatmap : public AActor
{
	GENERATED_BODY()

public:
	//-------------------------------------------
	//Constructors
	AHeatmap();

	//-------------------------------------------
	//Variables

	//Default resolution of the RenderTarget used
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Heatmap")
		float DefaultResolution;

	FString SaveRenderTargetPath;

	//-------------------------------------------
	//Functions

	//Draw to render target
	UFUNCTION(BlueprintCallable, Category = "Heatmap")
	virtual void DrawToRenderTargetFunction(FLinearColor LinearColor, FLinearColor FinalColor, float Size, float Strength, UTextureRenderTarget2D* RenderTargetRuntime, UMaterialInstanceDynamic* MID_HeatSplat);

	//Function for preparing the "Saved" folder for recieve the heatmaps
	UFUNCTION(BlueprintCallable, Category = "Heatmap")
		virtual void PrepareSaveRenderTarget();

	//Save a heatmap to the require saved folder
	UFUNCTION(BlueprintCallable, Category = "Heatmap")
		virtual void SaveRenderTarget(UTextureRenderTarget2D* RenderTarget);
};
