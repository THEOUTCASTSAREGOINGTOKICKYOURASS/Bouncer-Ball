// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "BouncerNet.h"
#include "Ball.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABouncerNet::ABouncerNet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Create the root CubeComponent to handle the pickup's collision
	BaseCollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BaseCollisionComponent"));

	//set the SubComponent as the root component
	RootComponent = BaseCollisionComponent;

	OnActorBeginOverlap.AddDynamic(this, &ABouncerNet::OnBeginOverlap);
}

void ABouncerNet::OnBeginOverlap_Implementation(AActor* OtherActor)
{

	GEngine->AddOnScreenDebugMessage(0, 1.f, FColor::Yellow, TEXT("Goal"));
	OtherActor->Destroy();
}