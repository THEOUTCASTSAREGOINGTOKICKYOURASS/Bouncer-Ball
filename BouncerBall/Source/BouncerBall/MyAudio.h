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

	UPROPERTY(EditAnywhere, Category = "Sounds")
		USoundCue* grow;
	UPROPERTY(EditAnywhere, Category = "Sounds")
		USoundCue* stun;
	UPROPERTY(EditAnywhere, Category = "Sounds")
		USoundCue* shrink;
	UPROPERTY(EditAnywhere, Category = "Sounds")
		USoundCue* ownall;
	UPROPERTY(EditAnywhere, Category = "Sounds")
		USoundCue* invincible;
	UPROPERTY(EditAnywhere, Category = "Sounds")
		USoundCue* steal;
	UPROPERTY(EditAnywhere, Category = "Sounds")
		USoundCue* speed;
	UPROPERTY(EditAnywhere, Category = "Sounds")
		USoundCue* slow;
	UPROPERTY(EditAnywhere, Category = "Sounds")
		USoundCue* Welcome;
	UPROPERTY(EditAnywhere, Category = "Sounds")
		USoundCue* Cheering;
	UPROPERTY(EditAnywhere, Category = "Sounds")
		USoundCue* RedScored;
	UPROPERTY(EditAnywhere, Category = "Sounds")
		USoundCue* YellowScored;
	UPROPERTY(EditAnywhere, Category = "Sounds")
		USoundCue* BlueScored;
	UPROPERTY(EditAnywhere, Category = "Sounds")
		USoundCue* GreenScored;
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
