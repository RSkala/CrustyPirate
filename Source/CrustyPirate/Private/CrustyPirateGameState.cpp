// Fill out your copyright notice in the Description page of Project Settings.

#include "CrustyPirateGameState.h"

DEFINE_LOG_CATEGORY_STATIC(LogCrustyPirateGameState, Log, All)

ACrustyPirateGameState::ACrustyPirateGameState()
{
	UE_LOG(LogCrustyPirateGameState, Log, TEXT("ACrustyPirateGameState::ACrustyPirateGameState - %s"), *GetName());
}

void ACrustyPirateGameState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACrustyPirateGameState::BeginPlay()
{
	UE_LOG(LogCrustyPirateGameState, Log, TEXT("ACrustyPirateGameState::BeginPlay - %s"), *GetName());
	Super::BeginPlay();
}
