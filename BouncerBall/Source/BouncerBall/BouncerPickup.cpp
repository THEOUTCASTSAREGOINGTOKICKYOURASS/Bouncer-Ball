// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "Ball.h"
#include "BouncerPickup.h"



// Sets default values
ABouncerPickup::ABouncerPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	Collider->SetSphereRadius(55.f);
	RootComponent = Collider;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachTo(RootComponent);
	OnActorBeginOverlap.AddDynamic(this, &ABouncerPickup::OnBeginOverlap);

}

void ABouncerPickup::OnBeginOverlap(AActor* OtherActor)
{
	Destroy();
}
