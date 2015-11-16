// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BouncerPowerUp.h"
/**
 * 
 */
class BOUNCERBALL_API OwnAllPowerUp:public BouncerPowerUp
{
public:
	OwnAllPowerUp(ABouncerPlayer *PlayerOwner);
	~OwnAllPowerUp();

	void Use(UWorld* WorldRef);
	void Over();
};
