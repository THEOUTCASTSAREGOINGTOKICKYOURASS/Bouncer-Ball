// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "BouncerHUD.h"
#include "BouncerBallGameMode.h"
#include "BouncerPlayer.h"
#include "Kismet/GameplayStatics.h"

ABouncerHUD::ABouncerHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//use the RobotoDisanceField font from the engine
	static ConstructorHelpers::FObjectFinder<UFont>HUDFontOB(TEXT("/Game/Fonts/COPRGTB"));
	HUDFont = (UFont*)HUDFontOB.Object;
}

void ABouncerHUD::DrawHUD()
{
	//Get the screen dimensions
	FVector2D ScreenDimensions = FVector2D(Canvas->SizeX, Canvas->SizeY);

	//Call to the parent versions of DrawHUD
	Super::DrawHUD();

	//Get the character and print its current points
	ABouncerPlayer* BouncerPlayer = Cast<ABouncerPlayer>(UGameplayStatics::GetPlayerPawn(this, 0));

	//UGameplayStatics::CreatePlayer(GetWorld(), 0, true);
	UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	UGameplayStatics::GetPlayerController(GetWorld(), 0);

	FString CurrentPointString = "Score: ";
	//Gets the CurrentPoints from the player and turns it into a String for the HUD
	//if (BouncerPlayer)
		//CurrentPointString += FString::Printf(TEXT("%d"), FMath::Abs(BouncerPlayer->CurrentPoints));

	//The dimensions 2D of the CurrentPointString
	FVector2D ScoreSize;
	GetTextSize(CurrentPointString, ScoreSize.X, ScoreSize.Y, HUDFont);
	//We Draw the Player's Current Points or Score on the top of the screen, Centered on the X
	DrawText(CurrentPointString, FColor::Black, (ScreenDimensions.X - ScoreSize.X) / 2.0f, 0, HUDFont);

	ABouncerBallGameMode* BouncerBallGameMode = Cast<ABouncerBallGameMode>(UGameplayStatics::GetGameMode(this));

	/*if (DragonSnakeGameMode->GetCurrentState() == EDragonSnakePlayState::EGameover)
	{
	FVector2D GameOverSize;
	GetTextSize(TEXT("GAME OVER"), GameOverSize.X, GameOverSize.Y, HUDFont);
	DrawText(TEXT("GAME OVER"), FColor::Black, (ScreenDimensions.X - GameOverSize.X) / 2.0f, (ScreenDimensions.Y - GameOverSize.X) / 2.0f, HUDFont);

	}*/
}


