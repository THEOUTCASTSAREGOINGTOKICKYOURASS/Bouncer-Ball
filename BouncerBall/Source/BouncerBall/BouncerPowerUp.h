// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
class BOUNCERBALL_API BouncerPowerUp
{
public:
	BouncerPowerUp();
	~BouncerPowerUp();

	virtual void Use() PURE_VIRTUAL(BouncerPowerUp::Use, );
};
