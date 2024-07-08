// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"

// Enums
UENUM(BlueprintType)
enum class ETestEnum : uint8 // In UE 5.4, enums MUST be uint8
{
	EnumVal1 UMETA(DisplayName = "Display Name for Enum Val 1"),
	EnumVal2 UMETA(DisplayName = "val 2"),
	EnumVal3,
	EnumVal4,
	Count UMETA(Hidden) // This cannot be seen or selected in the Blueprint
};
ENUM_RANGE_BY_COUNT(ETestEnum, ETestEnum::Count); // This is REQUIRED in order to iterate over it in C++ (i.e. TEnumRange)
//ENUM_RANGE_BY_FIRST_AND_LAST(ETestEnum, ETestEnum::EnumVal1, ETestEnum::EnumVal4); => Use this if you don't want a "Count" value
//ENUM_RANGE_BY_VALUES(...) => Use this if you have a non-contiguous range of values

UENUM()
enum class ETestEnum2 // This class cannot be used with Blueprints (because it is not marked as BlueprintType)
{
	Val1, Val2, Val3
};

// Bitflags / Bitmask test
UENUM(meta = (BitFlags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class ETestFlags
{
	CanFly = 1 << 0,
	CanSwim = 1 << 1,
	CanLayEggs = 1 << 2,
	CanPoop = 1 << 3
};
ENUM_CLASS_FLAGS(ETestFlags);

// Class for testing various UE5 things
UCLASS()
class CRUSTYPIRATE_API ATestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActor();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public: // Made public here for switching back to protected or private for testing
	UFUNCTION(BlueprintCallable)
	void BlueprintCallableFunction();

	// BlueprintPure functions must have a return type or output parameters
	UFUNCTION(BlueprintPure)
	bool BlueprintPureFunction() const;

	UFUNCTION(BlueprintPure)
	void BlueprintPureFunction2(int32& OutTestInt, bool& OutTestBool, FString& OutTestString);

	// BlueprintNativeEvent MUST have "_Implementation" in its C++ definition. This will usually always have green squiggles saying the definition is not found/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void BlueprintNativeEventFunction();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	int32 BlueprintNativeEventWithReturnFunction();

	// BlueprintImplementableEvent DOES NOT have a C++ definition. These are expected to be written in Blueprint Graphs
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void BlueprintImplementableEventFunction();

protected:
#if WITH_EDITOR
	virtual bool CanEditChange(const FProperty* InProperty) const override;
#endif

protected:
	// --- Components --- 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class USphereComponent> SphereComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UPaperSpriteComponent> PaperSpriteComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UStaticMeshComponent> StaticMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class USpringArmComponent> SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UCameraComponent> CameraComp;

	 // --- Various Test Values ---

	// Clamp value with manual edit and with ui slider
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestActor|Clamps", meta = (ClampMin = "0", ClampMax = "1234", UIMin = "0", UIMax = "1234"))
	float TestClampedAndUIClampedFloat;

	// Test Enumeration
	UPROPERTY(EditAnywhere, Category = "TestActor|Enums")
	ETestEnum TestEnum;

	// Test Enumeration with BitFlags
	UPROPERTY(EditAnywhere, Category = "TestActor|Enums", meta = (Bitmask, BitmaskEnum = ETestFlags))
	int32 TestFlags;
};
