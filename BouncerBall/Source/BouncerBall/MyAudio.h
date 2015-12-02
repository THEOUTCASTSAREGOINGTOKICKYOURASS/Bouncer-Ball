// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MyAudio.generated.h"

UCLASS()
class BOUNCERBALL_API AMyAudio : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyAudio();

	UPROPERTY(EditAnywhere, Category = "Sounds")
		TArray<USoundCue*> Sounds;
	UPROPERTY(EditAnywhere, Category = "Sounds")
		USoundCue* goal;
	UPROPERTY(EditAnywhere, Category = "Sounds")
		USoundCue* powerup;
	UPROPERTY(EditAnywhere, Category = "Audio Component")
		UAudioComponent* AudioComp;
	UFUNCTION()
		void PlaySound(USoundCue* Sound);



	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
private:
	UPROPERTY(EditAnywhere, Category = "Sounds")
		USoundCue* music;



};
