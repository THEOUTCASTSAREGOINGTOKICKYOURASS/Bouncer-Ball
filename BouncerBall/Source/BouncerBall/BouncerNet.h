// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BouncerPlayer.h"
#include "BouncerNet.generated.h"


UCLASS()
class BOUNCERBALL_API ABouncerNet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABouncerNet();

	//Collision Component
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = net)
	UBoxComponent* BaseCollisionComponent;

	UFUNCTION(BlueprintNativeEvent)
	void OnBeginOverlap(AActor* OtherActor);
	virtual void OnBeginOverlap_Implementation(AActor* OtherActor);
	//The player who owns this net
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ABouncerPlayer* PlayerOwner;
	
};
