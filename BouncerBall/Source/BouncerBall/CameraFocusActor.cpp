// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "CameraFocusActor.h"
#include "BouncerPlayer.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ACameraFocusActor::ACameraFocusActor()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = root;

	//CameraBoom = CreateDefaultSubobject<USpringArmComponent>(
	//TEXT("CameraBoom")
	//);
	//CameraBoom->SetRelativeRotation(FRotator(-35.f, 0.f, 0.f));
	//CameraBoom->AttachTo(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	//lock camera position
	Camera->SetAbsolute(true, true);
	//Camera->AttachTo(root);

}

// Called when the game starts or when spawned
void ACameraFocusActor::BeginPlay()
{
	Super::BeginPlay();
	Camera->SetWorldLocation(FVector(-1300, 0, 1500));
	Camera->SetWorldRotation(FRotator(-55, 0, 0));

	//Get the character and print its current points
	APlayerController* Player1 = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	APlayerController* Player2 = UGameplayStatics::GetPlayerController(GetWorld(), 1);
	APlayerController* Player3 = UGameplayStatics::GetPlayerController(GetWorld(), 2);
	APlayerController* Player4 = UGameplayStatics::GetPlayerController(GetWorld(), 3);

	if (Player1)
		Player1->SetViewTargetWithBlend(this);
	if (Player2)
		Player2->SetViewTargetWithBlend(this);
	if (Player3)
		Player3->SetViewTargetWithBlend(this);
	if (Player4)
		Player4->SetViewTargetWithBlend(this);
}

// Called every frame
void ACameraFocusActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

