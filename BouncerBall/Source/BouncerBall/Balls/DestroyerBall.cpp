// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "../PickUps/BouncerPickup.h"
#include "CollectorBall.h"
#include "DestroyerBall.h"

ADestroyerBall::ADestroyerBall()
{

}

void ADestroyerBall::NotifyHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	ACollectorBall* Balls = Cast<ACollectorBall>(Other);
	ABouncerPickup* Pickups = Cast<ABouncerPickup>(Other);

	if (Balls)
		Balls->Destroy();
	else if (Pickups)
		Pickups->Destroy();
}
