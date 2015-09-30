// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BouncerPlayer.h"
#include "Ball.generated.h"

UCLASS()
class BOUNCERBALL_API ABall : public AActor
{
	GENERATED_BODY()
	
public:
	UENUM()
	enum class EBallType : uint8
	{
		NORMAL, BLUDGER, TARGET,COLLECTOR, DESTROY
	};
	// Sets default values for this actor's properties
	ABall();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	//Call to set which type of ball it is Please do that in the constructor
	void SetType(EBallType type)
	{
		BallType = type;
	}
	
protected:
	//Called per frame in tick to move the Ball, must be overriden for your own movement
	UFUNCTION()
		virtual void Move();
	//Call to have the ball find a new target
	UFUNCTION()
		void GetTarget();
	//A reference to the current target of the ball
	UPROPERTY()
	ABouncerPlayer* CurrentTarget;
	UPROPERTY()
	EBallType BallType;
	
};

