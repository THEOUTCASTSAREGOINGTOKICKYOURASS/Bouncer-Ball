// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Ball.h"
#include "RegularBall.generated.h"

/**
 * 
 */
UCLASS()
class BOUNCERBALL_API ARegularBall : public ABall
{
	GENERATED_BODY()
	
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
public:
	ARegularBall();
	virtual void Move() override;
	
	
};
