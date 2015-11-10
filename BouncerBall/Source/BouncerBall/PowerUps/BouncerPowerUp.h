// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BouncerPlayer.h"
/**
 * 
 */
class ABouncerPlayer;

class BOUNCERBALL_API BouncerPowerUp
{
public:
	BouncerPowerUp(ABouncerPlayer* PlayerOwner);
	~BouncerPowerUp();

	virtual void Use() = 0;

protected:
	ABouncerPlayer *Owner;
};
