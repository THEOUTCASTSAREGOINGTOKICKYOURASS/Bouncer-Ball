// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerState.h"
#include "BouncerPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class BOUNCERBALL_API ABouncerPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	int32 Lives = 10;

	UPROPERTY()
	int32 RealScore = 0; //Can't access 'Score'
	UPROPERTY()
	bool bHasScored = false;
	
};
