// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BouncerPickup.generated.h"

UCLASS()
class BOUNCERBALL_API ABouncerPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABouncerPickup();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USphereComponent* Collider;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* Mesh;
	//this is used for instancing a power up to the player the other actor will always be a player so for each pickup there is a powerup that goes with it
	UFUNCTION()
		virtual void OnBeginOverlap(AActor* OtherActor);
	
};

