// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Ball.h"
#include "DestroyerBall.generated.h"

/**
 * 
 */
UCLASS()
class BOUNCERBALL_API ADestroyerBall : public ABall
{
	GENERATED_BODY()

public:
	ADestroyerBall();

	UFUNCTION()
		virtual bool HitPickup() override;

	//virtual void NotifyHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
};
