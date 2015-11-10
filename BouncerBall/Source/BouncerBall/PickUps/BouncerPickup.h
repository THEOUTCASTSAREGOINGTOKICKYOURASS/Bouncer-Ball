// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "../BouncerPlayer.h"
#include "../Balls/Ball.h"
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

	UFUNCTION()
		virtual void OnBeginOverlap(AActor* OtherActor);
	
};
