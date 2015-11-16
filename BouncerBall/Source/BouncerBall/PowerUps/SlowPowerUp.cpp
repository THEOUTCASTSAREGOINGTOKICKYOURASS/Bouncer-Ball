// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "SlowPowerUp.h"
#define SLOWED_TIME 3.f
#define SLOW_SCALAR 0.75f
SlowPowerUp::SlowPowerUp(ABouncerPlayer* PlayerOwner) :BouncerPowerUp(PlayerOwner)
{
}

SlowPowerUp::~SlowPowerUp()
{
}

void SlowPowerUp::Use(UWorld* WorldRef)
{
	BouncerPowerUp::Use(WorldRef);
	this->WorldRef = WorldRef;
	Owner->SetTimer(SLOWED_TIME);
	for (TActorIterator<ABouncerPlayer> ActorItr(WorldRef); ActorItr; ++ActorItr)
	{
		if (*ActorItr != Owner || !ActorItr->IsInvinsible())
		{
			ActorItr->SetMoveScalar(SLOW_SCALAR);
		}
	}
	
}
void SlowPowerUp::Over()
{
	for (TActorIterator<ABouncerPlayer> ActorItr(WorldRef); ActorItr; ++ActorItr)
	{
		if (*ActorItr != Owner)
		{

			if (ActorItr->GetMoveScale() == SLOW_SCALAR)
				ActorItr->SetMoveScalar(1.f);
		}
	}
}