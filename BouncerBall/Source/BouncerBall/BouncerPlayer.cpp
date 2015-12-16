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

	StunnedMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Stunned Mesh"));
	StunnedMesh->AttachTo(RootComponent);
	StunnedMeshTwo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Stunned Mesh Two"));
	StunnedMeshTwo->AttachTo(RootComponent);

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

	MoveSpeed = 15.f;
	rotSpeed = 10.f;
	TimeCounted = 0.f;
	TimeTillOver = 0.f;
	MoveScalar = 1.f;
	bIsStunned = false;
	bIsImmune = false;
	StoredPowerUp = nullptr;
	StolenPowerUp = nullptr;
	rotBounds = 35.f;
	returnSpeed = 10.f;
	SizeFactor = 1;
	SmallPowerUpUsed = 0;
	StunPowerUpUsed = 0;
	ScoredTime = 0.f;
}
bool ABouncerPlayer::HasScored()
{
	ABouncerPlayerState* State = Cast<ABouncerPlayerState>(PlayerState);
	if (State)
	{
		return State->bHasScored;
	}
	return false;
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

	StunnedMeshTwo->SetVisibility(false);
	StunnedMesh->SetVisibility(false);

	//set overhead camera position
	//Camera->SetWorldLocation(FVector(-1300, 0, 1500));
	//Camera->SetWorldRotation(FRotator(-55, 0, 0));

	APlayerController* PlayerController = Cast<APlayerController>(Controller);
	if (PlayerController)
		PlayerController->bForceFeedbackEnabled = true;
}

// Called every frame
void ABouncerPlayer::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	TimeCounted += DeltaTime;
	ABouncerPlayerState* State = Cast<ABouncerPlayerState>(PlayerState);
	if (State)
	{
		if (State->bHasScored)
		{
			ScoredTime += DeltaTime;
			if (ScoredTime >= 2)
			{
				State->bHasScored = false;
				ScoredTime = 0;
			}
		}
	}
	if (TimeTillOver != 0.f)
	{
		if (TimeCounted >= TimeTillOver)
		{
			if (StoredPowerUp)
				StoredPowerUp->Over();
			TimeTillOver = 0.f;
			delete StoredPowerUp;
			StoredPowerUp = nullptr;
			if (StolenPowerUp)
			{
				StoredPowerUp = StolenPowerUp;
				StolenPowerUp = nullptr;
			}
		}
	}
	FRotator CurrentRotation = StunnedMesh->GetComponentRotation();
	CurrentRotation.Yaw += (.0001 * DeltaTime) ;

	StunnedMesh->SetRelativeRotation(CurrentRotation);
	StunnedMeshTwo->SetRelativeRotation(CurrentRotation);
	
}

// Called to bind functionality to input
void ABouncerPlayer::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis(TEXT("Strafe"), this, &ABouncerPlayer::Strafe);

	InputComponent->BindAxis(TEXT("Rotate"), this, &ABouncerPlayer::Rotate);

	InputComponent->BindAction(TEXT("Shoot"), IE_Pressed, this, &ABouncerPlayer::Shoot);
	InputComponent->BindAction(TEXT("PowerUp"), IE_Pressed, this, &ABouncerPlayer::UsePowerUp);
	InputComponent->BindAction(TEXT("Reload"), IE_Pressed, this, &ABouncerPlayer::Reload);
	
}

void ABouncerPlayer::Reload()
{
	APlayerController* PlayerController1 = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	PlayerController1->ConsoleCommand(TEXT("RestartLevel"), true);
}

void ABouncerPlayer::Strafe(float Scale)
{
	if (bIsStunned)
		return;
	//stops the player from moving outside their bounds
	if (FVector::Dist(GetActorLocation(), leftBounds) > 20 && (bReverseControls ? Scale *-1 : Scale)<0)
	{
		AddActorWorldOffset(rightVector*(bReverseControls ? Scale *-1: Scale)* (MoveSpeed * MoveScalar));

	}
	else if (FVector::Dist(GetActorLocation(), rightBounds) > 20 && (bReverseControls ? Scale *-1 : Scale) > 0)
	{
		AddActorWorldOffset(rightVector*(bReverseControls ? Scale *-1 : Scale) * (MoveSpeed* MoveScalar));
	}
}

void ABouncerPlayer::Rotate(float Scale)
{
	if (bIsStunned)
		return;
	FRotator CurrentRotation = Mesh->GetComponentRotation();
	float MaxRotation = startRotation.Yaw + 45 * Scale;

	//CurrentRotation.Yaw += Scale * rotSpeed;
	if (Scale != 0)
	{
		CurrentRotation.Yaw = FMath::FInterpTo(CurrentRotation.Yaw, MaxRotation, GetWorld()->GetDeltaSeconds(), rotSpeed);

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
}
void ABouncerPlayer::UsePowerUp()
{
	if (!bIsStunned && StoredPowerUp && !StoredPowerUp->IsUsed())
	{
		TimeCounted = 0.f;
		USoundCue* Cue = nullptr;
		if (GetPowerUpName().Equals(TEXT("Grow"), ESearchCase::IgnoreCase))
		{
			Cue = AudioPlayer->grow;
		}
		else if (GetPowerUpName().Equals(TEXT("Invincible"), ESearchCase::IgnoreCase))
		{
			Cue = AudioPlayer->invincible;
		}
		else if (GetPowerUpName().Equals(TEXT("All Balls"), ESearchCase::IgnoreCase))
		{
			Cue = AudioPlayer->ownall;
		}
		else if (GetPowerUpName().Equals(TEXT("Slow"), ESearchCase::IgnoreCase))
		{
			Cue = AudioPlayer->slow;
		}
		else if (GetPowerUpName().Equals(TEXT("Small"), ESearchCase::IgnoreCase))
		{
			Cue = AudioPlayer->shrink;
		}
		else if (GetPowerUpName().Equals(TEXT("Speed"), ESearchCase::IgnoreCase))
		{
			Cue = AudioPlayer->speed;
		}
		else if (GetPowerUpName().Equals(TEXT("Steal"), ESearchCase::IgnoreCase))
		{
			Cue = AudioPlayer->steal;
		}
		else if (GetPowerUpName().Equals(TEXT("Stun"), ESearchCase::IgnoreCase))
		{
			Cue = AudioPlayer->stun;
		}
		AudioPlayer->PlaySound(Cue);
		StoredPowerUp->Use(GetWorld());
	}
}
void ABouncerPlayer::OnBeginOverlap(AActor* OtherActor)
{
	if (OtherActor->GetClass()->IsChildOf(ABall::StaticClass()))
	{
		ABall *ShootingBall = Cast<ABall>(OtherActor);
		
		if (ShootingBall)
		{
			APlayerController* PlayerController = Cast<APlayerController>(Controller);
			if (PlayerController)
			{
				PlayerController->ClientPlayForceFeedback(EffectClass, false, "Hit");
			}
			ShootingBall->SetOwner(this,SpotLight->GetLightColor());
		}
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
	SetActorScale3D(GetActorScale3D() / SHRINK_FACTOR);
}
void ABouncerPlayer::Shrink()
{
	SizeFactor--;
	SetActorScale3D(GetActorScale3D()* SHRINK_FACTOR);
}