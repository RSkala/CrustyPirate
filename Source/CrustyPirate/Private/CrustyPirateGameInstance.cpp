// Fill out your copyright notice in the Description page of Project Settings.


#include "CrustyPirateGameInstance.h"

DEFINE_LOG_CATEGORY_STATIC(LogCrustyPirateGameInstance, Log, All)

UCrustyPirateGameInstance::UCrustyPirateGameInstance()
{
	UE_LOG(LogCrustyPirateGameInstance, Log, TEXT("UCrustyPirateGameInstance::UCrustyPirateGameInstance - %s"), *GetName());
}

void UCrustyPirateGameInstance::Init()
{
	UE_LOG(LogCrustyPirateGameInstance, Log, TEXT("UCrustyPirateGameInstance::Init - %s"), *GetName());
	Super::Init();
}

void UCrustyPirateGameInstance::PostLoad()
{
	UE_LOG(LogCrustyPirateGameInstance, Log, TEXT("UCrustyPirateGameInstance::PostLoad - %s"), *GetName());
	Super::PostLoad();
}

void UCrustyPirateGameInstance::OnStart()
{
	UE_LOG(LogCrustyPirateGameInstance, Log, TEXT("UCrustyPirateGameInstance::OnStart - %s"), *GetName());
	Super::OnStart();
}
