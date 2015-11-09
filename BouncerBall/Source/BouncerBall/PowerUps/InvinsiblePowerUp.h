// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BouncerPowerUp.h"
/**
 * 
 */
class BOUNCERBALL_API InvinsiblePowerUp:public BouncerPowerUp
{
public:
	InvinsiblePowerUp(ABouncerPlayer *PlayerOwner);
	~InvinsiblePowerUp();

	void Use();
};
