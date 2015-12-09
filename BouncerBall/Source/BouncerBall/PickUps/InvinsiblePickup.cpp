// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "../PowerUps/InvinsiblePowerUp.h"
#include "InvinsiblePickup.h"

AInvinsiblePickup::AInvinsiblePickup()
{
	OnActorBeginOverlap.AddDynamic(this, &AInvinsiblePickup::OnBeginOverlap);
}

void AInvinsiblePickup::OnBeginOverlap(AActor* OtherActor)
{
	Super::OnBeginOverlap(OtherActor);

	ABall *Ball = Cast<ABall>(OtherActor);
	if (Ball)
	{
		if (Ball->HitPickup())
		{
			if (Ball->GetOwner())
				Ball->GetOwner()->SetPowerUp(new InvinsiblePowerUp(Ball->GetOwner()));
		}
	}
}