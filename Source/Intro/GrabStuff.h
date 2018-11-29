// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Classes/PhysicsEngine/PhysicsHandleComponent.h"
#include "Classes/Components/InputComponent.h"
#include "GrabStuff.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTRO_API UGrabStuff : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabStuff();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(VisibleAnywhere)
	float Reach = 100.0f;

	FVector LineEndPoint;
	
	UPhysicsHandleComponent *PhysicsHandle = nullptr;
	void RayTracing();

	UInputComponent *InputComponent = nullptr;
	void PickStuffUp();

	UInputComponent *InputComponent1 = nullptr;
	void LetItGo();

	void SetUpInputComponent();
	void SetUpPhysicsHandle();
};
