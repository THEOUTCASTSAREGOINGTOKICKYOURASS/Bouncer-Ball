// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "CollectorBall.h"

ACollectorBall::ACollectorBall()
{
	CurrentPickupTarget = nullptr;
}

// Called every frame
void ACollectorBall::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (!CurrentPickupTarget || CurrentPickupTarget->IsPendingKill())
	{
		if (!GetTarget())
		{
			CurrentPickupTarget = nullptr;
		}
	}
		
	//Turn the Minion to face the Player
	if (CurrentPickupTarget)
	{
		const FVector PlayerPos = CurrentPickupTarget->GetActorLocation();
		FVector Forward = (PlayerPos - this->GetActorLocation());
		FRotator PlayerRot = FRotationMatrix::MakeFromX(Forward).Rotator();
		this->SetActorRotation(GetActorRotation() - PlayerRot * DeltaSeconds);
	}


}

bool ACollectorBall::GetTarget()
{
	//Finds all Instances of SpawnVolumes and stores them into an array
	for (TActorIterator<ABouncerPickup> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		CurrentPickupTarget = *ActorItr;
		return true;
	}
	return false;
}