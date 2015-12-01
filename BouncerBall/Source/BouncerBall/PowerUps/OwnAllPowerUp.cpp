// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "../Balls/Ball.h"
#include "OwnAllPowerUp.h"

OwnAllPowerUp::OwnAllPowerUp(ABouncerPlayer *PlayerOwner) :BouncerPowerUp(PlayerOwner,"All Balls")
{
}

OwnAllPowerUp::~OwnAllPowerUp()
{
}

void OwnAllPowerUp::Use(UWorld* WorldRef)
{
	BouncerPowerUp::Use(WorldRef);
	Owner->SetTimer(0.1f);
	for (TActorIterator<ABall> ActorItr(WorldRef); ActorItr; ++ActorItr)
	{
		ActorItr->SetOwner(Owner,Owner->GetLightColor());
	}
}
void OwnAllPowerUp::Over()
{
	
}
