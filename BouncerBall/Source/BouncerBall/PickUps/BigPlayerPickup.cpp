// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "../PowerUps/BigPlayerPowerUp.h"
#include "BigPlayerPickup.h"




void ABigPlayerPickup::OnBeginOverlap(AActor *OtherActor)
{
	Super::OnBeginOverlap(OtherActor);
	ABall *Ball = Cast<ABall>(OtherActor);
	if (Ball)
	{
		if (Ball->GetOwner())
			Ball->GetOwner()->SetPowerUp(new BigPlayerPowerUp(Ball->GetOwner()));
	}
}