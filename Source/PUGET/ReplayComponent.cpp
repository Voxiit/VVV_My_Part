// Fill out your copyright notice in the Description page of Project Settings.


#include "ReplayComponent.h"
#include "Engine/World.h"
#include "GameFramework/WorldSettings.h"

// Sets default values for this component's properties
// Sets default values for this component's properties
UReplayComponent::UReplayComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	RecordingName = "MyReplay";
	FreindlyRecordingName = "My Replay";
}


void UReplayComponent::StartRecording(UGameInstance* GameInstance)
{
	FDateTime Date = FDateTime::UtcNow();
	RecordingName = Date.ToString();
	GameInstance->StartRecordingReplay(RecordingName, FreindlyRecordingName);
}

void UReplayComponent::StopRecording(UGameInstance* GameInstance)
{
	GameInstance->StopRecordingReplay();
}

void UReplayComponent::StartReplay(UGameInstance* GameInstance)
{
	GameInstance->PlayReplay(RecordingName, nullptr);
}

void UReplayComponent::StartGivenReplay(UGameInstance* GameInstance, FString ReplayName)
{
	GameInstance->PlayReplay(ReplayName, nullptr);
}

//Get all replays
void UReplayComponent::GetAllFilesInDirectory(const FString directory, const bool fullPath, const FString onlyFilesEndingWith)
{
    // Get all files in directory
    TArray<FString> directoriesToSkip;
    IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
    FLocalTimestampDirectoryVisitor Visitor(PlatformFile, directoriesToSkip, directoriesToSkip, false);
    PlatformFile.IterateDirectory(*directory, Visitor);

    for (TMap<FString, FDateTime>::TIterator TimestampIt(Visitor.FileTimes); TimestampIt; ++TimestampIt)
    {
        const FString filePath = TimestampIt.Key();
        const FString fileName = FPaths::GetCleanFilename(filePath);
        bool shouldAddFile = true;

        //Check file extension
        if (!onlyFilesEndingWith.IsEmpty())
        {
            if (!(FPaths::GetExtension(fileName, false).Equals(onlyFilesEndingWith, ESearchCase::IgnoreCase)))
                shouldAddFile = false;
        }

        //Add replay to array
        if (shouldAddFile)
        {
            UE_LOG(LogTemp, Warning, TEXT("File name : %s "), *fileName);
            Replays.Add(fileName);
        }
    }
}

TArray<FString> UReplayComponent::GetReplays()
{
    FString ReplayPath = FPaths::ProjectSavedDir() + "Demos";
	UE_LOG(LogTemp, Warning, TEXT("Get Replays"));
	GetAllFilesInDirectory(ReplayPath, true, Extension);
	return Replays;
}

// Called when the game starts
void UReplayComponent::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Replay Component start"));
}


// Called every frame
void UReplayComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

