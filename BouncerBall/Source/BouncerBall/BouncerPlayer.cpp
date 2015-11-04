// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "Ball.h"
#include "BouncerPlayer.h"


// Sets default values
ABouncerPlayer::ABouncerPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	SpotLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("SpotLight"));
	SpotLight->SetRelativeRotation(FRotator(90.f, 315.f, 90.f));
	SpotLight->SetRelativeLocation(FVector(0.f, 141.f, 80.f));
	SpotLight->AttachTo(Mesh);

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(
		TEXT("CameraBoom")
		);
	CameraBoom->SetRelativeRotation(FRotator(-35.f, 0.f, 0.f));
	CameraBoom->AttachTo(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(
		TEXT("Camera")
		);
	Camera->AttachTo(CameraBoom);

	OnActorBeginOverlap.AddDynamic(this, &ABouncerPlayer::OnBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &ABouncerPlayer::OnEndOverlap);

	MoveSpeed = 10.f;
}

// Called when the game starts or when spawned
void ABouncerPlayer::BeginPlay()
{
	Super::BeginPlay();
	//Set the bounds based on where the player starts
	rightBounds = GetActorLocation() + GetActorRightVector() * 250;
	leftBounds = GetActorLocation() + GetActorRightVector() *-250;
}

// Called every frame
void ABouncerPlayer::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

// Called to bind functionality to input
void ABouncerPlayer::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis(TEXT("Strafe"), this, &ABouncerPlayer::Strafe);

	InputComponent->BindAction(TEXT("Shoot"),
		IE_Pressed,
		this,
		&ABouncerPlayer::Shoot);
}

void ABouncerPlayer::Strafe(float Scale)
{
	GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Yellow, TEXT("Move"));
	//stops the player from moving outside their bounds
	if (FVector::Dist(GetActorLocation(), leftBounds) > 20 && Scale<0)
	{
		GEngine->AddOnScreenDebugMessage(2, 1.f, FColor::Yellow, TEXT("Left"));
		AddActorWorldOffset(GetActorRightVector()*Scale* MoveSpeed);

	}
	else if (FVector::Dist(GetActorLocation(), rightBounds) > 20 && Scale > 0)
	{
		GEngine->AddOnScreenDebugMessage(3, 1.f, FColor::Yellow, TEXT("Right"));
		AddActorWorldOffset(GetActorRightVector()*Scale * MoveSpeed);
	}
}
void ABouncerPlayer::Shoot()
{
	//if a ball is currently overlapping with the player calls the shoot function and passes in the new velocity	
	if (canShoot)
	{
		Cast<ABall>(Ball)->Shoot(GetActorForwardVector()*1000);
	}
}
void ABouncerPlayer::OnBeginOverlap(AActor* OtherActor)
{
	//sets true when a ball is overlaping with the player
	if (OtherActor->GetClass()->IsChildOf(ABall::StaticClass()))
	{
		canShoot = true;
		Ball = OtherActor;
	}
}
void ABouncerPlayer::OnEndOverlap(AActor* OtherActor)
{
	if (OtherActor->GetClass()->IsChildOf(ABall::StaticClass()))
	{
		canShoot = false;
	}
}

