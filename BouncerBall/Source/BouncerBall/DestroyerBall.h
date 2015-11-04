// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RegularBall.h"
#include "DestroyerBall.generated.h"

/**
 * 
 */
UCLASS()
class BOUNCERBALL_API ADestroyerBall : public ARegularBall
{
	GENERATED_BODY()

public:
	ADestroyerBall();

	virtual void NotifyHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
};
