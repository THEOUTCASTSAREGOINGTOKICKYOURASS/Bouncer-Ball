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
	BouncerPowerUp(ABouncerPlayer* PlayerOwner,FString Name);
	~BouncerPowerUp();

	virtual void Use(UWorld* WorldRef);
	virtual void Over() = 0;

	bool IsUsed()
	{
		return bIsUsed;
	}
	FString GetName()
	{
		return Name;
	}
protected:
	ABouncerPlayer *Owner;
private:
	bool bIsUsed;
	FString Name;
};
