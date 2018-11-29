// Fill out your copyright notice in the Description page of Project Settings.

#include "CloseDoor.h"
#include "GameFramework/Actor.h"
#include "Classes/Engine/World.h"

// Sets default values for this component's properties
UCloseDoor::UCloseDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCloseDoor::BeginPlay()
{
	Super::BeginPlay();
	MainActor = GetWorld()->GetFirstPlayerController()->GetPawn();
	// ...
	
}


// Called every frame
void UCloseDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (volume->IsOverlappingActor(MainActor))
	{
		FRotator R(0.0f, 0.0f, 0.0f);
		FQuat rotation(R);
		GetOwner()->SetActorRotation(rotation, ETeleportType::None);
	}
	// ...
}
