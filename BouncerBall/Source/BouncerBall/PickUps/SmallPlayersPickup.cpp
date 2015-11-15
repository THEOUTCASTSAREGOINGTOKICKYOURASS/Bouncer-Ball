// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "../PowerUps/SmallPlayersPowerUp.h"
#include "SmallPlayersPickup.h"

ASmallPlayersPickup::ASmallPlayersPickup()
{
	OnActorBeginOverlap.AddDynamic(this, &ASmallPlayersPickup::OnBeginOverlap);
}

void ASmallPlayersPickup::OnBeginOverlap(AActor* OtherActor)
{
	Super::OnBeginOverlap(OtherActor);
	ABall *Ball = Cast<ABall>(OtherActor);
	if (Ball)
	{
		if (Ball->GetOwner())
			Ball->GetOwner()->SetPowerUp(new SmallPlayersPowerUp(Ball->GetOwner()));
	}
}