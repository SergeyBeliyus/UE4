// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBasActor.h"

// Sets default values
ACppBasActor::ACppBasActor() : Amplitude(70), Frequency(4), InitialLocation(0, 0, 0)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ACppBasActor::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation = GetActorLocation();
}

FVector ACppBasActor::SinMovement()
{
	InitialLocation.Z = Amplitude * sin(Frequency * GetWorld()->GetTimeSeconds()) + InitialLocation.Z;
	return InitialLocation;
}

// Called every frame
void ACppBasActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
