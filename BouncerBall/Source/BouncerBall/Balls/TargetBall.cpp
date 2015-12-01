// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "TargetBall.h"

ATargetBall::ATargetBall()
{
	OnActorBeginOverlap.AddDynamic(this, &ATargetBall::OnBeginOverlap);
}

void ATargetBall::OnBeginOverlap(AActor* OtherActor)
{
	ABouncerPlayer* Player = Cast<ABouncerPlayer>(OtherActor);
	if (Player)
	{
		GetTarget();
	}
}