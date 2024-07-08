// Fill out your copyright notice in the Description page of Project Settings.


#include "CrustyPiratePlayerState.h"

DEFINE_LOG_CATEGORY_STATIC(LogCrustyPiratePlayerState, Log, All)

ACrustyPiratePlayerState::ACrustyPiratePlayerState()
{
	UE_LOG(LogCrustyPiratePlayerState, Log, TEXT("ACrustyPiratePlayerState::ACrustyPiratePlayerState - %s"), *GetName());
}

void ACrustyPiratePlayerState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACrustyPiratePlayerState::BeginPlay()
{
	UE_LOG(LogCrustyPiratePlayerState, Log, TEXT("ACrustyPiratePlayerState::BeginPlay - %s"), *GetName());
	Super::BeginPlay();
}
