// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "MyAudio.h"


// Sets default values
AMyAudio::AMyAudio()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	AudioComp = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComp"));
	RootComponent = AudioComp;
	AudioComp->Sound = music;
	AudioComp->bAutoActivate = false;

}

// Called when the game starts or when spawned
void AMyAudio::BeginPlay()
{
	AudioComp->Sound = music;
	AudioComp->Activate();
	
	Super::BeginPlay();
	
	
}

// Called every frame
void AMyAudio::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}
void AMyAudio::PlaySound(USoundCue* Sound)
{
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), Sound, this->GetActorLocation());
}

