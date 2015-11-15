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
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	//What the ball should do when the player hits it
	UFUNCTION()
	virtual void Shoot(FVector direction);
	UFUNCTION()
	ABouncerPlayer* GetOwner()
	{
		return BallOwner;
	}
	UFUNCTION()
	void SetOwner(ABouncerPlayer* NewOwner)
	{
		BallOwner = NewOwner;
	}
protected:
	//Called per frame in tick to move the Ball, override for your own movement, no need to call this in your implementation
	UFUNCTION()
	virtual void Move() PURE_VIRTUAL(ABall::Move,);
	//The Mesh for our Ball this will be set through blueprint
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UStaticMeshComponent *Mesh;
	//The Collider for the ball Good Times.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USphereComponent *Collider;
	//this is used to keep the balls from flying off into no where.
	float ZPos;
	//The light attached to the ball set in blueprint
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UPointLightComponent *Light;
	//The owner of this ball
	UPROPERTY()
	ABouncerPlayer *BallOwner;

	//Used to make the Ball move in blueprint
	UPROPERTY(VisibleAnywhere)
		UProjectileMovementComponent* MovementComponent;
private:
	float Time;
	bool bIsScaled;
};
