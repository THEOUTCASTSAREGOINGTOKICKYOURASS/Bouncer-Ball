// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BouncerAreanaObject.generated.h"

UCLASS()
class BOUNCERBALL_API ABouncerAreanaObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABouncerAreanaObject();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//The Mesh for our object this will be set through blueprint
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		UStaticMeshComponent *Mesh;
	//The Collider for the object Good Times.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USphereComponent *Collider;
	//The light attached to the object set in blueprint
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UPointLightComponent *Light;
protected:
	bool IsScaled()
	{
		return bIsScaled;
	}
private:
	float Time;
	bool bIsScaled;
	
};
