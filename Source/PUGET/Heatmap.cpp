// Fill out your copyright notice in the Description page of Project Settings.
#include "Heatmap.h"


// Sets default values
AHeatmap::AHeatmap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SaveRenderTargetPath = FPaths::ProjectDir() + "Heatmaps";
}


void AHeatmap::DrawToRenderTargetFunction(FLinearColor LinearColor, FLinearColor FinalColor, float Size, float Strength, UTextureRenderTarget2D* RenderTargetRuntime, UMaterialInstanceDynamic* MID_HeatSplat)
{
	//Set values to M_Heatsplat
	MID_HeatSplat->SetScalarParameterValue("Size", Size);
	MID_HeatSplat->SetScalarParameterValue("Strength", Strength);
	MID_HeatSplat->SetVectorParameterValue("Position", LinearColor);
	MID_HeatSplat->SetVectorParameterValue("FinalColor", FinalColor);

	//Draw to RT
	UKismetRenderingLibrary::DrawMaterialToRenderTarget(GetWorld(), RenderTargetRuntime, MID_HeatSplat);
}

void AHeatmap::PrepareSaveRenderTarget()
{
	//Prepare the save directory
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	// Directory Exists?
	if (!PlatformFile.DirectoryExists(*SaveRenderTargetPath))
	{
		PlatformFile.CreateDirectory(*SaveRenderTargetPath);
	}
}

void AHeatmap::SaveRenderTarget(UTextureRenderTarget2D* RenderTarget)
{
	//Prepare the file name
	FString FileName = FDateTime::UtcNow().ToString() + "_" + RenderTarget->GetName() + ".png";
	UE_LOG(LogTemp, Warning, TEXT("FileName = %s"), *FileName);
	UE_LOG(LogTemp, Warning, TEXT("SaveRenderTargetPath = %s"), *SaveRenderTargetPath);


	UKismetRenderingLibrary::ExportRenderTarget(GetWorld(), RenderTarget, SaveRenderTargetPath, FileName);
	/*
	UKismetRenderingLibrary::ExportRenderTarget(GetWorld(), RenderTarget, FPaths::GameAgnosticSavedDir() + "Heatmaps", FileName);
	UKismetRenderingLibrary::ExportRenderTarget(GetWorld(), RenderTarget, FPaths::GameSourceDir() + "Heatmaps", FileName);
	UKismetRenderingLibrary::ExportRenderTarget(GetWorld(), RenderTarget, FPaths::ProjectDir() + "Heatmaps", FileName);
	UKismetRenderingLibrary::ExportRenderTarget(GetWorld(), RenderTarget, FPaths::ProjectUserDir() + "Heatmaps", FileName);
	UKismetRenderingLibrary::ExportRenderTarget(GetWorld(), RenderTarget, FPaths::GetProjectFilePath() + "Heatmaps", FileName);
	*/
}


