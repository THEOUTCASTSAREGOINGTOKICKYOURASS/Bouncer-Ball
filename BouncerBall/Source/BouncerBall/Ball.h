// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BouncerPlayer.h"
#include "Ball.generated.h"
#define WEIGHT_COST 25
UCLASS()
class BOUNCERBALL_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();
protected:
	//Called per frame in tick to move the Ball, override for your own movement, no need to call this in your implementation
	UFUNCTION()
	virtual void Move() PURE_VIRTUAL(ABall::Move,);
	//Call to have the ball find a new target
	UFUNCTION()
	void GetTarget();
	//A reference to the current target of the ball
	UPROPERTY()
	ABouncerPlayer *CurrentTarget;
	//The Mesh for our Ball this will be set through blueprint
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UStaticMeshComponent *Mesh;
	//The Collider for the ball Good Times.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USphereComponent *Collider;
};
