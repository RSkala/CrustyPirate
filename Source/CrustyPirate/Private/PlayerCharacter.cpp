// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

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
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
