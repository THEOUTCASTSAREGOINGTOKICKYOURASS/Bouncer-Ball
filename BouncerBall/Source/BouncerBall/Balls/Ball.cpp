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
void ABall::GetTarget()
{
	int8 i = 0;
	int8 NumOfPlayers = 0;
	ABouncerPlayer* Players[4];
	//Finds all Instances of players and stores them into an array
	for (TActorIterator<ABouncerPlayer> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		Players[i] = *ActorItr;
		i++;

	}
	NumOfPlayers = i;
	/*Iterate through all the players and checks their weight
	the largest weight goes to the front if they have the same its a random pick between them
	after it iterates through them all the player in the first index is chosen as the target*/
	for (i = 1; i < NumOfPlayers; i++)
	{

		if (Players[i]->GetWeight() > Players[0]->GetWeight())
		{
			ABouncerPlayer *temp = Players[0];
			Players[0] = Players[i];
			Players[i] = temp;
		}
		else if (Players[i]->GetWeight() == Players[0]->GetWeight())
		{
			int RandomNumber = FMath::Rand() % 2;
			if (RandomNumber == 0)
			{
				continue;
			}
			else
			{
				ABouncerPlayer *temp = Players[0];
				Players[0] = Players[i];
				Players[i] = temp;
			}
		}
	}
	CurrentTarget = Players[0]; 
	CurrentTarget->SetWeight(CurrentTarget->GetWeight() - WEIGHT_COST);
}
void ABall::Shoot(FVector Direction)
{
	GetTarget();
}