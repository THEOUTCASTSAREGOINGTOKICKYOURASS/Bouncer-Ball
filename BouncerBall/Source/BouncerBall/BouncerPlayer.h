// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PowerUps/BouncerPowerUp.h"
#include "BouncerPlayerState.h"
#include "MyAudio.h"
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
	bool SetPowerUp(BouncerPowerUp* NewPowerUp)
	{
		if (StoredPowerUp)
			return false;
		StoredPowerUp = NewPowerUp;
		return true;
	}
	bool HasPowerUp()
	{
		if (StoredPowerUp && !StoredPowerUp->IsUsed())
		{
			return true;
		}
		return false;
	}
	BouncerPowerUp* StealPowerUp()
	{
		BouncerPowerUp* temp = StoredPowerUp;
		StoredPowerUp = nullptr;
		return temp;
	}
	void SetStolenPowerUp(BouncerPowerUp* PowerUp)
	{
		StolenPowerUp = PowerUp;
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
	//Used for the big and small powerups
	void Grow();
	void Shrink();
	//Used to keep track of what size the player is 0 = small 1 = regular 2 = big
	int8 GetSize()
	{
		return SizeFactor;
	}
	//Used to keep track of how many stuns were used
	void GotStunned()
	{
		StunnedMesh->SetVisibility(true);
		StunnedMeshTwo->SetVisibility(true);
		StunPowerUpUsed++;
	}
	void StunIsOver()
	{
		StunnedMesh->SetVisibility(false);
		StunnedMeshTwo->SetVisibility(false);
		StunPowerUpUsed--;
		if (StunPowerUpUsed < 0)
			StunPowerUpUsed = 0;
	}
	int8 GetStunnedCounter()
	{
		return StunPowerUpUsed;
	}
	//Used to keep track of shrinks used
	void GotShrunk()
	{
		SmallPowerUpUsed++;
	}
	void ShrunkOver()
	{
		SmallPowerUpUsed--;
	}
	int8 GetShrunkCounter()
	{
		return SmallPowerUpUsed;
	}
	FString GetPowerUpName()
	{
		if (StoredPowerUp)
		{
			if (!StoredPowerUp->IsUsed())
				return StoredPowerUp->GetName();
			else
				return StoredPowerUp->GetName() + " Used : " + FString::FromInt(TimeTillOver - TimeCounted);
		}
			
		return "";
	}
	FLinearColor GetLightColor()
	{
		return SpotLight->GetLightColor();
	}
	bool HasScored();
protected:
	//Function to that allows the player to strafe
	UFUNCTION()
	virtual void Strafe(float Scale);

	UFUNCTION()
	virtual void Rotate(float Scale);

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

	UFUNCTION()
	virtual void Reload();

public:

	/// StaticMesh component that will be the visuals for our flying pawn 
	UPROPERTY(Category = Mesh, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StunnedMesh;
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* StunnedMeshTwo;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* root;

	//Not needed for overhead camera
	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USpringArmComponent* CameraBoom;*/

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	//UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBoxComponent* Collider;

	UPROPERTY(EditAnywhere)
	AMyAudio* AudioPlayer;

	UPROPERTY(EditAnywhere, Category = "Sounds")
	USoundCue* ScoredSound;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USpotLightComponent* SpotLight;
	UPROPERTY(EditAnywhere)
		UForceFeedbackEffect* EffectClass;
	//A value that will be modified by the balls after targetting to make sure there is an even distrobution of targeting for RNG
	int8 Weight;
	//Used to set the movement boundaries
	FVector leftBounds;
	FVector rightBounds;
	FVector rightVector;

	UPROPERTY(Editanywhere)
		bool bReverseControls;

	//Set to true when a ball is overlaping with the player
	bool canShoot;
	// the ball that is overlaping with the player
	AActor* Ball;
	//The current pickup of the player
	BouncerPowerUp* StoredPowerUp,*StolenPowerUp;

	//Used for the power up timer counts time spent
	float TimeCounted;
	//Used for the power ups to say when they have ended
	float TimeTillOver;
	//The Starting rotation
	FRotator startRotation;
	//Max angle the player can rotate
	float rotBounds;

private:
	//Speed the player rotates at
	float rotSpeed;
	//The Speed the paddle reutrns to starting rotation
	float returnSpeed;
	/** Current speed */
	float MoveSpeed;
	//Timer for the boolean being true in the player state
	float ScoredTime;
	//Scalar for movement power ups
	float MoveScalar;
	//if true negative powerups dont work
	bool bIsImmune;
	//if true player can not move
	bool bIsStunned;
	//Keep track if shrunken or bigger 0 = small 1 = regular 2 = big
	int8 SizeFactor;
	//Keeps track of how many smalls have been used on this player that have not expired
	int8 SmallPowerUpUsed;
	//Keeps track of how many stuns have been used on this player that have not expired
	int8 StunPowerUpUsed;
};
