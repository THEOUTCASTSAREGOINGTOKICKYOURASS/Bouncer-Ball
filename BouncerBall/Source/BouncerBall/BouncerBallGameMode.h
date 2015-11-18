// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "BouncerBallGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BOUNCERBALL_API ABouncerBallGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ABouncerBallGameMode(const FObjectInitializer& ObjectInitializer);
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
};
