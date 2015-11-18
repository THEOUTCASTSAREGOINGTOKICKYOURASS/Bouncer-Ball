// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "BouncerBallGameMode.h"
#include "BouncerPlayerState.h"
#include "BouncerHUD.h"

ABouncerBallGameMode::ABouncerBallGameMode(
	const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinder<UBlueprint> CharacterClass;
		FConstructorStatics()
			: CharacterClass(
			TEXT("Blueprint'/Game/Blueprints/Character/Player'")
			)
		{
		}
	};

	static FConstructorStatics ConstructorStatics;

	if (ConstructorStatics.CharacterClass.Object)
	{
		DefaultPawnClass = Cast<UClass>(
			ConstructorStatics.CharacterClass.Object->GeneratedClass);
	}

	HUDClass = ABouncerHUD::StaticClass();
	PlayerStateClass = ABouncerPlayerState::StaticClass();
}

// Called when the game starts or when spawned
void ABouncerBallGameMode::BeginPlay()
{
	Super::BeginPlay();

	//for splitscreen
	/*UGameplayStatics::CreatePlayer(GetWorld(), 0, true);
	UGameplayStatics::CreatePlayer(GetWorld(), 1, true);
	UGameplayStatics::CreatePlayer(GetWorld(), 2, true);
	UGameplayStatics::CreatePlayer(GetWorld(), 3, true);*/
}




