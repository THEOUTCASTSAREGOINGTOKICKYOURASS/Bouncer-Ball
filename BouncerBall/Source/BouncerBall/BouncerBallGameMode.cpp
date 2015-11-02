// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "BouncerBallGameMode.h"

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
}




