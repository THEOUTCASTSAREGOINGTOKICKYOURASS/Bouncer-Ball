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
	if (!CurrentPickupTarget)
		GetTarget();
	//Turn the Minion to face the Player
	if (CurrentPickupTarget != nullptr)
	{
		const FVector PlayerPos = CurrentPickupTarget->GetActorLocation();
		FVector Forward = (PlayerPos - this->GetActorLocation());
		FRotator PlayerRot = FRotationMatrix::MakeFromX(Forward).Rotator();
		this->SetActorRotation(GetActorRotation() - PlayerRot * DeltaSeconds);
	}


}

void ACollectorBall::GetTarget()
{
	ABouncerPickup* PickUps[4];
	int8 i = 0, j = 0;
	//Finds all Instances of SpawnVolumes and stores them into an array
	for (TActorIterator<ABouncerPickup> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		PickUps[i] = *ActorItr;
		i++;
	}
	if (PickUps[0])
		CurrentPickupTarget = PickUps[0];
}