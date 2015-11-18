// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "Balls/Ball.h"
#include "BouncerPlayer.h"

#define GROW_FACTOR 1.5f
#define SHRINK_FACTOR 0.5f
// Sets default values
ABouncerPlayer::ABouncerPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachTo(RootComponent);
	Mesh->SetRelativeLocation(FVector(0.f, 0.f, 0.f));

	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	Collider->AttachTo(RootComponent);

	SpotLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("SpotLight"));
	SpotLight->SetRelativeRotation(FRotator(90.f, 315.f, 90.f));
	SpotLight->SetRelativeLocation(FVector(0.f, 141.f, 80.f));
	SpotLight->AttachTo(Mesh);

	//CameraBoom = CreateDefaultSubobject<USpringArmComponent>(
		//TEXT("CameraBoom")
		//);
	//CameraBoom->SetRelativeRotation(FRotator(-35.f, 0.f, 0.f));
	//CameraBoom->AttachTo(RootComponent);

	//Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	//lock camera position
	//Camera->SetAbsolute(true, true);
	//Camera->AttachTo(CameraBoom);

	OnActorBeginOverlap.AddDynamic(this, &ABouncerPlayer::OnBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &ABouncerPlayer::OnEndOverlap);

	MoveSpeed = 10.f;
	rotSpeed = 1.f;
	TimeCounted = 0.f;
	TimeTillOver = 0.f;
	MoveScalar = 1.f;
	bIsStunned = false;
	bIsImmune = false;
	StoredPowerUp = nullptr;
	rotBounds = 35.f;
	returnSpeed = 10.f;

}

// Called when the game starts or when spawned
void ABouncerPlayer::BeginPlay()
{
	Super::BeginPlay();
	//Set the bounds based on where the player starts
	rightVector = GetActorRightVector();
	rightBounds = GetActorLocation() + GetActorRightVector() * 250;
	leftBounds = GetActorLocation() + GetActorRightVector() *-250;
	startRotation = Mesh->GetComponentRotation();

	//set overhead camera position
	//Camera->SetWorldLocation(FVector(-1300, 0, 1500));
	//Camera->SetWorldRotation(FRotator(-55, 0, 0));
}

// Called every frame
void ABouncerPlayer::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	TimeCounted += DeltaTime;
	if (TimeTillOver != 0.f)
	{
		if (TimeCounted >= TimeTillOver)
		{
			this->StoredPowerUp->Over();
			TimeTillOver = 0.f;
			delete StoredPowerUp;
			StoredPowerUp = nullptr;
		}
	}
}

// Called to bind functionality to input
void ABouncerPlayer::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis(TEXT("Strafe"), this, &ABouncerPlayer::Strafe);

	InputComponent->BindAxis(TEXT("Rotate"), this, &ABouncerPlayer::Rotate);

	InputComponent->BindAction(TEXT("Shoot"),
		IE_Pressed,
		this,
		&ABouncerPlayer::Shoot);
}

void ABouncerPlayer::Strafe(float Scale)
{
	if (bIsStunned)
		return;
	//stops the player from moving outside their bounds
	if (FVector::Dist(GetActorLocation(), leftBounds) > 20 && Scale<0)
	{
		AddActorWorldOffset(rightVector*Scale* (MoveSpeed * MoveScalar));

	}
	else if (FVector::Dist(GetActorLocation(), rightBounds) > 20 && Scale > 0)
	{
		AddActorWorldOffset(rightVector*Scale * (MoveSpeed* MoveScalar));
	}
}

void ABouncerPlayer::Rotate(float Scale)
{
	FRotator CurrentRotation = Mesh->GetComponentRotation();

	CurrentRotation.Yaw += Scale * rotSpeed;
	if (Scale != 0)
	{
		CurrentRotation.Yaw += Scale * rotSpeed;

		if (CurrentRotation.Yaw < startRotation.Yaw + 45 && CurrentRotation.Yaw > startRotation.Yaw - 45)
		{
			Mesh->SetWorldRotation(CurrentRotation);
		}
	}
	else
	{

		CurrentRotation = FMath::RInterpTo(CurrentRotation, startRotation, GetWorld()->GetDeltaSeconds(), returnSpeed);
		Mesh->SetWorldRotation(CurrentRotation);
	}
}

void ABouncerPlayer::Shoot()
{
	//if a ball is currently overlapping with the player calls the shoot function and passes in the new velocity	
	if (canShoot && !bIsStunned)
	{
	}
}
void ABouncerPlayer::UsePowerUp()
{
	if (!bIsStunned && StoredPowerUp && !StoredPowerUp->IsUsed())
	{
		TimeCounted = 0.f;
		StoredPowerUp->Use(GetWorld());
	}
}
void ABouncerPlayer::OnBeginOverlap(AActor* OtherActor)
{
	//sets true when a ball is overlaping with the player
	if (OtherActor->GetClass()->IsChildOf(ABall::StaticClass()))
	{
		ABall *ShootingBall = Cast<ABall>(OtherActor);
		
		if (ShootingBall)
		{
			ShootingBall->SetOwner(this);
			ShootingBall->SetLightColor(SpotLight->GetLightColor());
			//ShootingBall->Shoot(GetActorForwardVector() * 1000);
		}
		
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

void ABouncerPlayer::Grow()
{
	SizeFactor++;
	SetActorScale3D(GetActorScale3D() * GROW_FACTOR);
}
void ABouncerPlayer::Shrink()
{
	SizeFactor--;
	SetActorScale3D(GetActorScale3D()* SHRINK_FACTOR);
}