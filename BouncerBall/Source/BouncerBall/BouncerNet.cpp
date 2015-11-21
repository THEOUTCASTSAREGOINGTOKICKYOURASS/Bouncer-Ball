// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "BouncerNet.h"
#include "Balls/Ball.h"
#include "Kismet/GameplayStatics.h"
#include "BouncerPlayerState.h"
#include "SpawnVolume.h"

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
	ABall* Ball = Cast<ABall>(OtherActor);
	if (Ball)
	{
		if (Ball->GetOwner())
		{
			ABouncerPlayerState* State = Cast<ABouncerPlayerState>(Ball->GetOwner()->PlayerState);

			if (State)
			{
				if (Ball->GetOwner() == PlayerOwner)
				{
					State->RealScore--;
					if (State->RealScore <= 0)
						State->RealScore = 0;
				}
				else
					State->RealScore++;
			}
			
		}
	}
	OtherActor->Destroy();
}