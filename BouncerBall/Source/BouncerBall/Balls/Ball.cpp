// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "Ball.h"
#include "../SpawnVolume.h"
#include "EngineUtils.h"


// Sets default values
ABall::ABall() :ZPos(0.f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	FRotator Rotator;
	Rotator.Add(0.f, FMath::Rand() % 360,0.f);
	SetActorRotation(Rotator);

	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(
		TEXT("MovementComponent"));
	MovementComponent->ProjectileGravityScale = 0.0f;
	MovementComponent->bShouldBounce = true;
	MovementComponent->Bounciness = 1.0f;
	MovementComponent->Friction = 0.0f;
	MovementComponent->BounceVelocityStopSimulatingThreshold = 0.0f;
	MovementComponent->MaxSpeed = 1000.f;
	bStartedMoving = false;
}
void ABall::BeginPlay()
{
	//Get the Z position of the ball on start for locking
	ZPos = GetActorLocation().Z;
}
void ABall::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (IsScaled() && !bStartedMoving)
	{
		bStartedMoving = true;
		MovementComponent->SetVelocityInLocalSpace(GetActorForwardVector()*1000);
	}
		

	//Get the current Position of the Ball and set its Z to the start up Z position 
	FVector pos = GetActorLocation();
	pos.Z = ZPos;
	SetActorLocation(pos);


	
}
void ABall::Shoot(FVector Direction)
{
	//set the direction of the ball to the players forward vector
	MovementComponent->Velocity = Direction;
}