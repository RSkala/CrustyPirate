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
		// Move
		EnhancedInputComponent->BindAction(MoveInputAction, ETriggerEvent::Triggered, this, &ThisClass::Move);

		// Jump
		EnhancedInputComponent->BindAction(JumpInputAction, ETriggerEvent::Started, this, &ThisClass::JumpStarted);
		EnhancedInputComponent->BindAction(JumpInputAction, ETriggerEvent::Completed, this, &ThisClass::JumpEnded);
		EnhancedInputComponent->BindAction(JumpInputAction, ETriggerEvent::Canceled, this, &ThisClass::JumpEnded);

		// Attack
		EnhancedInputComponent->BindAction(AttackInputAction, ETriggerEvent::Started, this, &ThisClass::Attack);
	}
}

void APlayerCharacter::Move(const FInputActionValue& InputActionValue)
{
	UE_LOG(LogPlayerCharacter, Log, TEXT("APlayerCharacter::Move - %s"), *GetName());

	float MoveActionValue = InputActionValue.Get<float>();

	if (bIsAlive && bCanMove)
	{
		FVector MovementDirection = FVector(1.0f, 0.0f, 0.0f); // Could also use FVector::ForwardVector (since we are in XZ plane and +X is FORWARD)
		AddMovementInput(MovementDirection, MoveActionValue); // AddMovementInput() is from APawn

		// NOTE: We do not need to handle speed here, as that is handled in the Blueprint
	}
}

void APlayerCharacter::JumpStarted(const FInputActionValue& InputActionValue)
{
	UE_LOG(LogPlayerCharacter, Log, TEXT("APlayerCharacter::JumpStarted - %s"), *GetName());

	if (bIsAlive && bCanMove)
	{
		Jump(); // Jump() is from ACharacter / CharacterMovementComponent

		// NOTE: We handle and setup all "Jump" values from the Blueprint
	}
}

void APlayerCharacter::JumpEnded(const FInputActionValue& InputActionValue)
{
	UE_LOG(LogPlayerCharacter, Log, TEXT("APlayerCharacter::JumpEnded - %s"), *GetName());
	StopJumping(); // StopJumping() is from ACharacter / CharacterMovementComponent
}

void APlayerCharacter::Attack(const FInputActionValue& InputActionValue)
{
	UE_LOG(LogPlayerCharacter, Log, TEXT("APlayerCharacter::Attack - %s"), *GetName());
}
