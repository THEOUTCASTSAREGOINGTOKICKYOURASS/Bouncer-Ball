// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BouncerPowerUp.h"
/**
 * 
 */
class BOUNCERBALL_API SlowPowerUp:public BouncerPowerUp
{
public:
	SlowPowerUp(ABouncerPlayer *PlayerOwner);
	~SlowPowerUp();

	void Use();
};
