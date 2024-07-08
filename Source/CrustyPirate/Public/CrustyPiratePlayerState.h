// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "CrustyPiratePlayerState.generated.h"

UCLASS()
class CRUSTYPIRATE_API ACrustyPiratePlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	ACrustyPiratePlayerState();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
};
