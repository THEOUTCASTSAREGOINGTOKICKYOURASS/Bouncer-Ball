// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"

#include "../PowerUps/StunPowerUp.h"
#include "StunPickup.h"

AStunPickup::AStunPickup()
{
	OnActorBeginOverlap.AddDynamic(this, &AStunPickup::OnBeginOverlap);
}

void AStunPickup::OnBeginOverlap(AActor* OtherActor)
{
	Super::OnBeginOverlap(OtherActor);
	ABall *Ball = Cast<ABall>(OtherActor);
	if (Ball)
	{
		if (Ball->GetOwner())
			Ball->GetOwner()->SetPowerUp(new StunPowerUp(Ball->GetOwner()));
	}
}



