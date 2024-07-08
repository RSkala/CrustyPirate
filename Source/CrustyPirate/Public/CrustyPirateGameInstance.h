// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CrustyPirateGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CRUSTYPIRATE_API UCrustyPirateGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UCrustyPirateGameInstance();

	virtual void Init() override;
	virtual void PostLoad() override;
protected:
	virtual void OnStart() override;
};
