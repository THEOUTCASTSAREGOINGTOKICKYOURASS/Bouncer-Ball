// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "SpawnVolume.h"
#include "Balls/Ball.h"

// Sets default values
ASpawnVolume::ASpawnVolume()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create the root CubeComponent to handle the pickup's collision
	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));

	//set the SubComponent as the root component
	RootComponent = WhereToSpawn;
	bSpawningEnabled = true;
	ArraySize = 0;
}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	for (ArraySize = 0; ArraySize < SPAWNER_ARRAY_SIZE; ArraySize++)
	{
		if (!WhatToSpawn[ArraySize])
		{
			break;
		}
	}
	SpawnPickup();
}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!SpawnedPickup || SpawnedPickup->IsPendingKill())
	{
		SpawnPickup();
	}
}

void ASpawnVolume::SpawnPickup()
{
	// If we have set something to spawn:
	if (WhatToSpawn[0] != NULL)
	{
		// Check for a valid World: 
		UWorld* const World = GetWorld();
		if (World)
		{
			// Set the spawn parameters
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;

			// Get a random location to spawn at
			FVector SpawnLocation = GetRandomPointInVolume();

			// Get a random rotation for the spawned item
			FRotator SpawnRotation;
			SpawnRotation.Yaw = FMath::FRand() * 360.f;
			SpawnRotation.Pitch = 0.f;
			SpawnRotation.Roll = 0.f;

			// spawn the pickup
			SpawnedPickup = World->SpawnActor<AActor>(WhatToSpawn[FMath::Rand()%ArraySize], SpawnLocation, SpawnRotation, SpawnParams);
		}
	}
}

FVector ASpawnVolume::GetRandomPointInVolume()
{
	FVector RandomLocation;
	float MinX, MinY, MinZ;
	float MaxX, MaxY, MaxZ;

	FVector Origin;
	FVector BoxExtent;

	// Get the SpawnVolume's origin and box extent
	Origin = WhereToSpawn->Bounds.Origin;
	BoxExtent = WhereToSpawn->Bounds.BoxExtent;

	// Calculate the minimum X, Y, and Z
	MinX = Origin.X - BoxExtent.X / 2.f;
	MinY = Origin.Y - BoxExtent.Y / 2.f;
	MinZ = Origin.Z - BoxExtent.Z / 2.f;

	// Calculate the maximum X, Y, and Z
	MaxX = Origin.X + BoxExtent.X / 2.f;
	MaxY = Origin.Y + BoxExtent.Y / 2.f;
	MaxZ = Origin.Z + BoxExtent.Z / 2.f;

	// The random spawn location will fall between the min and max X, Y, and Z
	RandomLocation.X = FMath::FRandRange(MinX, MaxX);
	RandomLocation.Y = FMath::FRandRange(MinY, MaxY);
	RandomLocation.Z = 70;

	// Return the random spawn location
	return RandomLocation;
}

void ASpawnVolume::EnableSpawning()
{
	bSpawningEnabled = true;
}

void ASpawnVolume::DisableSpawning()
{
	bSpawningEnabled = false;
}

