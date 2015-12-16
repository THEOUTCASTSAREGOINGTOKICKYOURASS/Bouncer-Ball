// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PlayerTargetingBall.h"
#include "TargetBall.generated.h"

/**
 * 
 */
UCLASS()
class BOUNCERBALL_API ATargetBall : public APlayerTargetingBall
{
	GENERATED_BODY()
public:
	ATargetBall();
	UFUNCTION()
	virtual void OnBeginOverlap(AActor* OtherActor);

	
	
};
