// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Engine/GameInstance.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "Misc/LocalTimestampDirectoryVisitor.h" 
#include "Misc/Paths.h"
#include "HAL/FileManager.h"
#include "Logging/LogVerbosity.h"
#include "ReplayComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PUGET_API UReplayComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UReplayComponent();

	UPROPERTY(EditDefaultsOnly, Category = "Replays")
		FString RecordingName;

	UPROPERTY(EditDefaultsOnly, Category = "Replays")
		FString FreindlyRecordingName;

	UFUNCTION(BlueprintCallable, Category = "Replays")
		void StartRecording(UGameInstance* GameInstance);

	UFUNCTION(BlueprintCallable, Category = "Replays")
		void StopRecording(UGameInstance* GameInstance);

	UFUNCTION(BlueprintCallable, Category = "Replays")
		void StartReplay(UGameInstance* GameInstance);

	UFUNCTION(BlueprintCallable, Category = "Replays")
		void StartGivenReplay(UGameInstance* GameInstance, FString ReplayName);

	UFUNCTION(BlueprintCallable, Category = "Replays")
		TArray<FString> GetReplays();

private :
	TArray<FString> Replays;
	FString Extension = "replay";

	void GetAllFilesInDirectory(const FString directory, const bool fullPath = true, const FString onlyFilesEndingWith = TEXT(""));

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;		
};
