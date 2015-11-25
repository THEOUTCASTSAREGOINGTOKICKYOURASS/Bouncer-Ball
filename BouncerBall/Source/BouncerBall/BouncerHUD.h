// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "BouncerHUD.generated.h"

/**
 * 
 */
UCLASS()
class BOUNCERBALL_API ABouncerHUD : public AHUD
{
	GENERATED_BODY()
	
	//Variable for storing the font
	UPROPERTY()
	UFont* HUDFont;

	//Primary draw call for the HUD
	virtual void DrawHUD() override;

public:
	ABouncerHUD(const FObjectInitializer& ObjectInitializer);

private:
	float GameTime;
};
