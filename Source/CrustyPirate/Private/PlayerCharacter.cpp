// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "GameFramework/Controller.h"

DEFINE_LOG_CATEGORY_STATIC(LogPlayerCharacter, Log, All)

APlayerCharacter::APlayerCharacter()
{
	UE_LOG(LogPlayerCharacter, Log, TEXT("APlayerCharacter::APlayerCharacter - %s"), *GetName());

	PrimaryActorTick.bCanEverTick = true;

	// Create Components -- RootComponent already exists and should be the CapsuleComponent
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
}

void APlayerCharacter::BeginPlay()
{
	UE_LOG(LogPlayerCharacter, Log, TEXT("APlayerCharacter::BeginPlay - %s"), *GetName());

	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMappingContext, 0);
		}
	}
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	UE_LOG(LogPlayerCharacter, Log, TEXT("APlayerCharacter::SetupPlayerInputComponent - %s"), *GetName());
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up Input Action Binding
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// TODO
	}
}

void APlayerCharacter::Move(const FInputActionValue& InputActionValue)
{
	UE_LOG(LogPlayerCharacter, Log, TEXT("APlayerCharacter::Move - %s"), *GetName());
}

void APlayerCharacter::JumpStarted(const FInputActionValue& InputActionValue)
{
	UE_LOG(LogPlayerCharacter, Log, TEXT("APlayerCharacter::JumpStarted - %s"), *GetName());
}

void APlayerCharacter::JumpEnded(const FInputActionValue& InputActionValue)
{
	UE_LOG(LogPlayerCharacter, Log, TEXT("APlayerCharacter::JumpEnded - %s"), *GetName());
}

void APlayerCharacter::Attack(const FInputActionValue& InputActionValue)
{
	UE_LOG(LogPlayerCharacter, Log, TEXT("APlayerCharacter::Attack - %s"), *GetName());
}
