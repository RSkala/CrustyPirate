// Fill out your copyright notice in the Description page of Project Settings.

#include "TestActor.h"

#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PaperSpriteComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogTestActor, Log, All)

// Sets default values
ATestActor::ATestActor()
{
	UE_LOG(LogTestActor, Log, TEXT("ATestActor::ATestActor - %s"), *GetName());

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// --- Components ---
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Sphere"));
	SetRootComponent(SphereComp);

	PaperSpriteComp = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Paper Sprite"));
	PaperSpriteComp->SetupAttachment(RootComponent);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	StaticMeshComp->SetupAttachment(RootComponent);

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Spring Arm"));
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName); // Attach to "SpringEndpoint"

	// Class Default Object experiementation
	UObject* ClassDefaultObject = ATestActor::StaticClass()->GetDefaultObject();
	FString CDOName = ClassDefaultObject != nullptr ? ClassDefaultObject->GetName() : TEXT("(invalid CDO)");
	UE_LOG(LogTestActor, Log, TEXT("ATestActor CDO Name: %s"), *CDOName);

	if (HasAnyFlags(EObjectFlags::RF_ClassDefaultObject))
	{
		UE_LOG(LogTestActor, Log, TEXT(" -> This is the Class Default Object: %s"), *GetName());
	}

	if (HasAnyFlags(EObjectFlags::RF_Transient))
	{
		UE_LOG(LogTestActor, Log, TEXT(" -> This object is Transient: %s"), *GetName());
	}

	if (HasAnyFlags(EObjectFlags::RF_Transactional))
	{
		UE_LOG(LogTestActor, Log, TEXT(" -> This object is Transactional: %s"), *GetName());
	}

	if (HasAnyFlags(EObjectFlags::RF_ArchetypeObject))
	{
		UE_LOG(LogTestActor, Log, TEXT(" -> This object is ArchetypeObject: %s"), *GetName());
	}

	//
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	UE_LOG(LogTestActor, Log, TEXT("ATestActor::BeginPlay - %s"), *GetName());
	Super::BeginPlay();

	// Calling Blueprint functions for testing:
	BlueprintNativeEventFunction();
	BlueprintImplementableEventFunction();
}

void ATestActor::BlueprintCallableFunction()
{
	UE_LOG(LogTestActor, Log, TEXT("ATestActor::BlueprintCallableFunction - %s"), *GetName());
}

bool ATestActor::BlueprintPureFunction() const
{
	UE_LOG(LogTestActor, Log, TEXT("ATestActor::BlueprintPureFunction - %s"), *GetName());
	return true;
}

void ATestActor::BlueprintPureFunction2(int32& OutTestInt, bool& OutTestBool, FString& OutTestString)
{
	UE_LOG(LogTestActor, Log, TEXT("ATestActor::BlueprintPureFunction2 - %s"), *GetName());
	//OutTestInt = 1234;
	//OutTestString = "1234";
	OutTestInt = 1234;
	OutTestBool = false;
	OutTestString = "test";
}

#if WITH_EDITOR
bool ATestActor::CanEditChange(const FProperty* InProperty) const
{

	// Check the property name using the following:
	// const FName InPropertyName = InProperty != nullptr ? InProperty->GetFName() : NAME_None;
	// const FName SomePropertyName = GET_MEMBER_NAME_CHECKED(ATestActor, SomePropertyName);
	// if (InPropertyName == SomePropertyName)

	return Super::CanEditChange(InProperty);
}
#endif // WITH_EDITOR

void ATestActor::BlueprintNativeEventFunction_Implementation()
{
	UE_LOG(LogTestActor, Log, TEXT("ATestActor::BlueprintNativeEventFunction_Implementation - %s"), *GetName());
}

int32 ATestActor::BlueprintNativeEventWithReturnFunction_Implementation()
{
	UE_LOG(LogTestActor, Log, TEXT("ATestActor::BlueprintNativeEventWithReturnFunction_Implementation - %s"), *GetName());
	return 54321;
}

//void ATestActor::BlueprintImplementableEventFunction()
//{
//	UE_LOG(LogTestActor, Log, TEXT("ATestActor::BlueprintImplementableEventFunction - %s"), *GetName());
//}

