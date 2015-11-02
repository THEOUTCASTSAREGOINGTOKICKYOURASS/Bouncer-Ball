// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "BouncerPlayer.generated.h"

UCLASS()
class BOUNCERBALL_API ABouncerPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABouncerPlayer();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	int8 GetWeight()
	{
		return Weight;
	}
	void SetWeight(int8 amount)
	{
		Weight -= amount;
	}
protected:
	//Function to that allows the player to strafe
	UFUNCTION()
	virtual void Strafe(float Scale);
	//Call the shoot function on the ball when it's overlaping with the player
	UFUNCTION()
	virtual void Shoot();
	

	UFUNCTION()
	virtual void OnBeginOverlap(AActor* OtherActor);

	UFUNCTION()
	virtual void OnEndOverlap(AActor* OtherActor);

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UCameraComponent* Camera;

protected:
	//A value that will be modified by the balls after targetting to make sure there is an even distrobution of targeting for RNG
	int8 Weight;
	//Used to set the movement boundaries
	FVector leftBounds;
	FVector rightBounds;
	
	//Set to true when a ball is overlaping with the player
	bool canShoot;
	// the ball that is overlaping with the player
	AActor* Ball;


	
};
