// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "StunPowerUp.h"

#define STUN_LENGTH 2.f
StunPowerUp::StunPowerUp(ABouncerPlayer* PlayerOwner) :BouncerPowerUp(PlayerOwner)
{
}

StunPowerUp::~StunPowerUp()
{
}

void StunPowerUp::Use(UWorld* WorldRef)
{
	BouncerPowerUp::Use(WorldRef);
	this->WorldRef = WorldRef;
	for (TActorIterator<ABouncerPlayer> ActorItr(WorldRef); ActorItr; ++ActorItr)
	{
		if (*ActorItr != Owner || !ActorItr->IsInvinsible())
		{
			ActorItr->SetTimer(STUN_LENGTH);
			ActorItr->SetStunned(true);
		}
	}
}
void StunPowerUp::Over()
{
	for (TActorIterator<ABouncerPlayer> ActorItr(WorldRef); ActorItr; ++ActorItr)
	{
		if (*ActorItr != Owner)
		{
			ActorItr->SetStunned(false);
		}
	}
}
