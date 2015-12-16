// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../BouncerAreanaObject.h"
#include "../BouncerPlayer.h"
#include "../Balls/Ball.h"
#include "BouncerPickup.generated.h"

UCLASS()
class BOUNCERBALL_API ABouncerPickup : public ABouncerAreanaObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABouncerPickup();

	UFUNCTION()
		virtual void OnBeginOverlap(AActor* OtherActor);
	
};
