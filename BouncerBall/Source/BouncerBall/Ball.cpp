// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "Ball.h"
#include "EngineUtils.h"


// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	Collider->SetSphereRadius(55.f);
	RootComponent = Collider;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachTo(RootComponent);
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