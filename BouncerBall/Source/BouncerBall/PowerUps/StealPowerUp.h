// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BouncerPowerUp.h"
/**
 * 
 */
class BOUNCERBALL_API StealPowerUp:public BouncerPowerUp
{
public:
	StealPowerUp(ABouncerPlayer *PlayerOwner);
	~StealPowerUp();

	void Use(UWorld* WorldRef);
	void Over();
};
