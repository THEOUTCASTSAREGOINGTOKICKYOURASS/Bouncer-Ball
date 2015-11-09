// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BouncerPowerUp.h"
/**
 * 
 */
class BOUNCERBALL_API SpeedPowerUp:public BouncerPowerUp
{
public:
	SpeedPowerUp(ABouncerPlayer *PlayerOwner);
	~SpeedPowerUp();

	void Use();
};
