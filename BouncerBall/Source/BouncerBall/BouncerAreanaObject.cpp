// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "BouncerAreanaObject.h"


// Sets default values
ABouncerAreanaObject::ABouncerAreanaObject()
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
	Light->SetRelativeLocation(FVector(0.f, 0.f, 120.f));
}

// Called when the game starts or when spawned
void ABouncerAreanaObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABouncerAreanaObject::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (Time < .5f)
	{
		Time += DeltaTime;
		SetActorRelativeScale3D(FVector(Time * 2, Time * 2, Time * 2));
		Light->SetIntensity(1000 * Time);
	}
	else
	{
		if (!bIsScaled)
		{
			bIsScaled = true;
			SetActorRelativeScale3D(FVector(1.f, 1.f, 1.f));

		}

	}

}

