// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "../PowerUps/SpeedPowerUp.h"
#include "SpeedPickup.h"

ASpeedPickup::ASpeedPickup()
{
	OnActorBeginOverlap.AddDynamic(this, &ASpeedPickup::OnBeginOverlap);
}

void ASpeedPickup::OnBeginOverlap(AActor* OtherActor)
{
	Super::OnBeginOverlap(OtherActor);

	ABall *Ball = Cast<ABall>(OtherActor);
	if (Ball)
	{
		if (Ball->HitPickup())
		{
			if (Ball->GetOwner())
				Ball->GetOwner()->SetPowerUp(new SpeedPowerUp(Ball->GetOwner()));
		}
	}
}