// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class CRUSTYPIRATE_API APlayerCharacter : public APaperZDCharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

	// public, from ACharacter
	virtual void BeginPlay() override;

	// public, from AActor
	virtual void Tick(float DeltaTime) override;

	// public, from ACharacter
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Functions to Bind to our InputActions:

	void Move(const struct FInputActionValue& InputActionValue);
	void JumpStarted(const struct FInputActionValue& InputActionValue);
	void JumpEnded(const struct FInputActionValue& InputActionValue);
	void Attack(const struct FInputActionValue& InputActionValue);

	void UpdateDirection(float MoveDirection);

protected:
	// --- Components ---

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class USpringArmComponent> SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UCameraComponent> CameraComp;

	// --- Input ---

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<class UInputMappingContext> InputMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<class UInputAction> MoveInputAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<class UInputAction> JumpInputAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<class UInputAction> AttackInputAction;

	// --- Lifetime / Movement

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bIsAlive = true;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bCanMove = true;
};
