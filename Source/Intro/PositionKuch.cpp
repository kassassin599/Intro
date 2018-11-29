// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionKuch.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UPositionKuch::UPositionKuch()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPositionKuch::BeginPlay()
{
	Super::BeginPlay();

	FString NameOfString = GetOwner()->GetName();
	FString PositionOfString = GetOwner()->GetTransform().GetLocation().ToString();


	UE_LOG(LogTemp, Warning, TEXT("Ready For Work on %s at position %s"), *NameOfString, *PositionOfString)
	// ...
	
}


// Called every frame
void UPositionKuch::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

