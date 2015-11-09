// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "BouncerPlayer.h"
#include "InvinsiblePickup.h"



void AInvinsiblePickup::OnBeginOverlap(AActor* OtherActor)
{
	Super::OnBeginOverlap(OtherActor);

	ABouncerPlayer* OtherPlayer = Cast<ABouncerPlayer>(OtherActor);
	if (OtherPlayer)
	{
	
	}
}