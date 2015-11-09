// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BouncerPowerUp.h"
/**
 * 
 */
class BOUNCERBALL_API SmallPlayersPowerUp:public BouncerPowerUp
{
public:
	SmallPlayersPowerUp(ABouncerPlayer *PlayerOwner);
	~SmallPlayersPowerUp();

	void Use();
};
