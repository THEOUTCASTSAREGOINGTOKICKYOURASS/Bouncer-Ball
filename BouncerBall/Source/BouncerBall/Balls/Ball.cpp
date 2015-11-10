// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "Ball.h"
#include "EngineUtils.h"


// Sets default values
ABall::ABall() :ZPos(0.f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	Collider->SetSphereRadius(55.f);
	RootComponent = Collider;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachTo(RootComponent);

	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));
	Light->AttachTo(RootComponent);
	FRotator Rotator;
	Rotator.Add(0.f, FMath::Rand() % 360,0.f);
	SetActorRotation(Rotator);
	
}
void ABall::BeginPlay()
{
	//Get the Z position of the ball on start for locking
	ZPos = GetActorLocation().Z;
}
void ABall::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	//Get the current Position of the Ball and set its Z to the start up Z position 
	FVector pos = GetActorLocation();
	pos.Z = ZPos;
	SetActorLocation(pos);
}
void ABall::Shoot(FVector Direction)
{
}