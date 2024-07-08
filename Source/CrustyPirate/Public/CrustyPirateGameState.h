// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "CrustyPirateGameState.generated.h"

/**
 * 
 */
UCLASS()
class CRUSTYPIRATE_API ACrustyPirateGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	ACrustyPirateGameState();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	
};
