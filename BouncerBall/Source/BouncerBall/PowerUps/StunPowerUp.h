// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BouncerPowerUp.h"
/**
 * 
 */
class BOUNCERBALL_API StunPowerUp:public BouncerPowerUp
{
public:
	StunPowerUp(ABouncerPlayer *PlayerOwner);
	~StunPowerUp();

	void Use();
};
