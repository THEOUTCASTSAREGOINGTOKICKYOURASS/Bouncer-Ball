// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "PlayerTargetingBall.h"
APlayerTargetingBall::APlayerTargetingBall()
{
	
	MovementComponent->HomingAccelerationMagnitude = 1100;
}
void APlayerTargetingBall::BeginPlay()
{
	Super::BeginPlay();
	GetTarget();
	MovementComponent->bIsHomingProjectile = true;
}

void APlayerTargetingBall::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

}
void APlayerTargetingBall::RotateToTarget(float DeltaSeconds)
{
	
}
void APlayerTargetingBall::GetTarget()
{
	int8 i = 0;
	int8 NumOfPlayers = 0;
	ABouncerPlayer* Players[4];
	//Finds all Instances of players and stores them into an array
	for (TActorIterator<ABouncerPlayer> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		Players[i] = *ActorItr;
		i++;

	}
	CurrentTarget = Players[FMath::RandRange(0,i-1)]; 
	CurrentTarget->SetWeight(CurrentTarget->GetWeight() - WEIGHT_COST);
	MovementComponent->HomingTargetComponent = CurrentTarget->Collider;
}
