// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BouncerPowerUp.h"
/**
 * 
 */
class BOUNCERBALL_API BigPlayerPowerUp:public BouncerPowerUp
{
public:
	BigPlayerPowerUp(ABouncerPlayer *PlayerOwner);
	~BigPlayerPowerUp();
	void Use();
};
