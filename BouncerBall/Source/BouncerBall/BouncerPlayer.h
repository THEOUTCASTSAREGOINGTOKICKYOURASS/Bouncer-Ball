// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PowerUps/BouncerPowerUp.h"
#include "BouncerPlayer.generated.h"

class BouncerPowerUp;

UCLASS()
class BOUNCERBALL_API ABouncerPlayer : public APawn
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
	void SetPowerUp(BouncerPowerUp* NewPowerUp)
	{
		StoredPowerUp = NewPowerUp;
	}
	void SetInvinsible(bool value)
	{
		bIsImmune = value;
	}
	bool IsInvinsible()
	{
		return bIsImmune;
	}
	//Sets how long the power up lasts
	void SetTimer(float TimerMax)
	{
		TimeTillOver = TimerMax;
	}
	void SetMoveScalar(float Scalar)
	{
		MoveScalar = Scalar;
	}
	float GetMoveScale()
	{
		return MoveScalar;
	}

	void SetStunned(bool Stunned)
	{
		bIsStunned = Stunned;
	}


protected:
	//Function to that allows the player to strafe
	UFUNCTION()
	virtual void Strafe(float Scale);
	//Call the shoot function on the ball when it's overlaping with the player
	UFUNCTION()
	virtual void Shoot();
	//Use the Powerup thats stored if valid
	UFUNCTION()
	void UsePowerUp();

	UFUNCTION()
	virtual void OnBeginOverlap(AActor* OtherActor);

	UFUNCTION()
	virtual void OnEndOverlap(AActor* OtherActor);

public:

	/// StaticMesh component that will be the visuals for our flying pawn 
	UPROPERTY(Category = Mesh, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USpotLightComponent* SpotLight;


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
	//The current pickup of the player
	BouncerPowerUp* StoredPowerUp;

	//Used for the power up timer counts time spent
	float TimeCounted;
	//Used for the power ups to say when they have ended
	float TimeTillOver;

private:
	/** Current speed */
	float MoveSpeed;
	//Scalar for movement power ups
	float MoveScalar;
	//if true negative powerups dont work
	bool bIsImmune;
	//if true player can not move
	bool bIsStunned;
	
};
