<<<<<<< HEAD
// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "Ball.h"


// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	Move();
}

// Called every frame
void ABall::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}
void ABall::GetTarget()
{

}
void ABall::Move()
{

=======
// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "Ball.h"


// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ABall::Move()
{

}
void ABall::GetTarget()
{

>>>>>>> origin/master
}