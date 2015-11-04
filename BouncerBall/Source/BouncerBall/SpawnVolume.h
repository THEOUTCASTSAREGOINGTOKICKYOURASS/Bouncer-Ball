// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class BOUNCERBALL_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	//BoxComponent to specify the spawning area within the level
	UPROPERTY(VisibleInstanceOnly, Category = Spawning)
		UBoxComponent* WhereToSpawn;

	//The pickup to spawn
	UPROPERTY(EditAnywhere, Category = Spawning)
		TSubclassOf<class ABall> WhatToSpawn;

	//finds a random point within the BoxComponent
	UFUNCTION(BlueprintPure, Category = Spawning)
		FVector GetRandomPointInVolume();

	void EnableSpawning();

	void DisableSpawning();

	/** Handles the spawning of a new pickup */
	UFUNCTION(/*BlueprintCallable,*/ Category = Spawning)
		void SpawnPickup();

private:

	/** Whether or not spawning is enabled */
	bool bSpawningEnabled;

	//ADragonSnakePickup* SpawnedPickup;

	
	
};
