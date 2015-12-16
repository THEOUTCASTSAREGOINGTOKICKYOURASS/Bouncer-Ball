// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "CollectorBall.h"
#include "../PickUps/BouncerPickup.h"

ACollectorBall::ACollectorBall()
{
	CurrentPickupTarget = nullptr;
}

void ACollectorBall::BeginPlay()
{
	Super::BeginPlay();
	GetTarget();
	MovementComponent->bIsHomingProjectile = true;
	MovementComponent->HomingAccelerationMagnitude = 1100;
}

// Called every frame
void ACollectorBall::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

bool ACollectorBall::GetTarget()
{
	//Finds all Instances of SpawnVolumes and stores them into an array
	for (TActorIterator<ABouncerPickup> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		CurrentPickupTarget = *ActorItr;
		MovementComponent->HomingTargetComponent = CurrentPickupTarget->Collider;
		return true;
	}
	return false;
}

bool ACollectorBall::HitPickup()
{
	MovementComponent->bIsHomingProjectile = false;
	return true;
}