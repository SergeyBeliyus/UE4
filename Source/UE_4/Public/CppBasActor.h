// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBasActor.generated.h"

UENUM(BlueprintType)
enum class EMovementState : uint8
{
	Dynamic,
	Static
};


UCLASS()
class UE_4_API ACppBasActor : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ACppBasActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	FVector SinMovement();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	float Amplitude;

	UPROPERTY(EditAnywhere)
	float Frequency;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector InitialLocation;
};

