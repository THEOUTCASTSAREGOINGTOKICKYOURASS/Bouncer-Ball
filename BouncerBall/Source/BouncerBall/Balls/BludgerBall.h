// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PlayerTargetingBall.h"
#include "BludgerBall.generated.h"

/**
 * 
 */
UCLASS()
class BOUNCERBALL_API ABludgerBall : public APlayerTargetingBall
{
	GENERATED_BODY()
	
public:
	ABludgerBall();
	UFUNCTION()
	virtual void OnBeginOverlap(AActor* OtherActor);
	
private:
	int8 HitCounter;
};
