// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "BludgerBall.h"


ABludgerBall::ABludgerBall()
{
	OnActorBeginOverlap.AddDynamic(this, &ABludgerBall::OnBeginOverlap);
}

void ABludgerBall::OnBeginOverlap(AActor* OtherActor)
{
	ABouncerPlayer* Player = Cast<ABouncerPlayer>(OtherActor);
	if (Player)
	{
		HitCounter++;
		if ((FMath::Rand()%3) < HitCounter)
		GetTarget();
	}
}