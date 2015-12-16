// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "../PowerUps/OwnAllPowerUp.h"
#include "OwnAllPickup.h"


AOwnAllPickup::AOwnAllPickup()
{
	OnActorBeginOverlap.AddDynamic(this, &AOwnAllPickup::OnBeginOverlap);
}

void AOwnAllPickup::OnBeginOverlap(AActor* OtherActor)
{
	Super::OnBeginOverlap(OtherActor);

	ABall *Ball = Cast<ABall>(OtherActor);
	if (Ball)
	{
		if (Ball->HitPickup())
		{
			if (Ball->GetOwner())
				Ball->GetOwner()->SetPowerUp(new OwnAllPowerUp(Ball->GetOwner()));
		}
	}
}