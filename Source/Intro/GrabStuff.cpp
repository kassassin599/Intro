// Fill out your copyright notice in the Description page of Project Settings.

#include "GrabStuff.h"
#include "Classes/Engine/World.h"
#include "public/DrawDebugHelpers.h"
#define OUT

#define UPROPERTY

// Sets default values for this component's properties
UGrabStuff::UGrabStuff()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabStuff::BeginPlay()
{
	Super::BeginPlay();

	SetUpPhysicsHandle();

	SetUpInputComponent();
	
}


// Called every frame
void UGrabStuff::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
	//UE_LOG(LogTemp, Warning, TEXT("Location is %s, and Ratation is %s"), *Location.ToString(), *Rotator.ToString());

	// ...
	

	/*DrawDebugLine(
		GetWorld(),
		Location,
		LineEndPoint,
		FColor::Red,
		false,
		0.01f,
		0,
		1.0f
	);*/


}

void UGrabStuff::RayTracing()
{
	FVector Location;
	FRotator Rotator;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(Location, Rotator);

	LineEndPoint = Location + Rotator.Vector() * Reach;

	FHitResult Hit;

	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		Location,
		LineEndPoint,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		FCollisionQueryParams(FName(TEXT("")), false, GetOwner())
	);


	//return Hit;
}

void UGrabStuff::PickStuffUp() {
	UE_LOG(LogTemp, Warning, TEXT("Trying to pick stuff up"));
	RayTracing();
}


void UGrabStuff::LetItGo() {
	UE_LOG(LogTemp, Warning, TEXT("Let go of the stuff"));
}

void UGrabStuff::SetUpInputComponent() {
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("Input Component is missing on %s"), *GetOwner()->GetName());
	}
	else {
		InputComponent->BindAction("PickUp", EInputEvent::IE_Pressed, this, &UGrabStuff::PickStuffUp);
		InputComponent->BindAction("PickUp", EInputEvent::IE_Released, this, &UGrabStuff::LetItGo);
	}
}

void UGrabStuff::SetUpPhysicsHandle() {
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("Physics handle component is missing on %s"), *GetOwner()->GetName());
	}
}