// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "BouncerNet.h"


// Sets default values
ABouncerNet::ABouncerNet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABouncerNet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABouncerNet::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

