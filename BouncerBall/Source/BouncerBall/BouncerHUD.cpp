// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "BouncerHUD.h"
#include "BouncerBallGameMode.h"
#include "BouncerPlayer.h"
#include "BouncerPlayerState.h"
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
	ABouncerPlayer* Player1 = Cast<ABouncerPlayer>(UGameplayStatics::GetPlayerPawn(this, 0));
	ABouncerPlayer* Player2 = Cast<ABouncerPlayer>(UGameplayStatics::GetPlayerPawn(this, 1));
	ABouncerPlayer* Player3 = Cast<ABouncerPlayer>(UGameplayStatics::GetPlayerPawn(this, 2));
	ABouncerPlayer* Player4 = Cast<ABouncerPlayer>(UGameplayStatics::GetPlayerPawn(this, 3));

	//UGameplayStatics::CreatePlayer(GetWorld(), 0, true);
	UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	UGameplayStatics::GetPlayerController(GetWorld(), 0);

	FString CurrentPointString1 = "Score: ";
	FString CurrentPointString2 = "Score: ";
	FString CurrentPointString3 = "Score: ";
	FString CurrentPointString4 = "Score: ";

	FString PowerUpPlayerOne = "";
	FString PowerUpPlayerTwo = "";
	FString PowerUpPlayerThree = "";
	FString PowerUpPlayerFour = "";

	APlayerController* PlayerController1 = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerController1)
	{
		PowerUpPlayerOne = Player1->GetPowerUpName(); 
		ABouncerPlayerState* PlayerState1 = Cast<ABouncerPlayerState>(PlayerController1->PlayerState);
		if (PlayerState1)
		{
			CurrentPointString1 += FString::Printf(TEXT("%d"), FMath::Abs(PlayerState1->RealScore));
		}
		else
			CurrentPointString1 += "-2";
	}
	else
		CurrentPointString1 += "-1";

	APlayerController* PlayerController2 = UGameplayStatics::GetPlayerController(GetWorld(), 1);
	if (PlayerController2)
	{
		PowerUpPlayerTwo = Player2->GetPowerUpName();
		ABouncerPlayerState* PlayerState2 = Cast<ABouncerPlayerState>(PlayerController2->PlayerState);
		if (PlayerState2)
		{
			CurrentPointString2 += FString::Printf(TEXT("%d"), FMath::Abs(PlayerState2->RealScore));
		}
		else
			CurrentPointString2 += "-2";
	}
	else
		CurrentPointString2 += "-1";

	APlayerController* PlayerController3 = UGameplayStatics::GetPlayerController(GetWorld(), 2);
	if (PlayerController3)
	{
		PowerUpPlayerThree = Player3->GetPowerUpName();
		ABouncerPlayerState* PlayerState3 = Cast<ABouncerPlayerState>(PlayerController3->PlayerState);
		if (PlayerState3)
		{
			CurrentPointString3 += FString::Printf(TEXT("%d"), FMath::Abs(PlayerState3->RealScore));
		}
		else
			CurrentPointString3 += "-2";
	}
	else
		CurrentPointString3 += "-1";

	APlayerController* PlayerController4 = UGameplayStatics::GetPlayerController(GetWorld(), 3);
	if (PlayerController4)
	{
		PowerUpPlayerFour = Player4->GetPowerUpName();
		ABouncerPlayerState* PlayerState4 = Cast<ABouncerPlayerState>(PlayerController4->PlayerState);
		if (PlayerState4)
		{
			CurrentPointString4 += FString::Printf(TEXT("%d"), FMath::Abs(PlayerState4->RealScore));
		}
		else
			CurrentPointString4 += "-2";
	}
	else
		CurrentPointString4 += "-1";

	//The dimensions 2D of the CurrentPointString
	FVector2D ScoreSize, ScoreSize1, ScoreSize2, ScoreSize3, ScoreSize4,PowerUpSizeOne,PowerUpSizeTwo,PowerUpSizeThree,PowerUpSizeFour;
	GetTextSize(CurrentPointString1, ScoreSize1.X, ScoreSize1.Y, HUDFont);
	GetTextSize(CurrentPointString2, ScoreSize2.X, ScoreSize2.Y, HUDFont);
	GetTextSize(CurrentPointString3, ScoreSize3.X, ScoreSize3.Y, HUDFont);
	GetTextSize(CurrentPointString4, ScoreSize4.X, ScoreSize4.Y, HUDFont);

	GetTextSize(PowerUpPlayerOne, PowerUpSizeOne.X, PowerUpSizeOne.Y, HUDFont);
	GetTextSize(PowerUpPlayerTwo, PowerUpSizeTwo.X, PowerUpSizeTwo.Y, HUDFont);
	GetTextSize(PowerUpPlayerThree, PowerUpSizeThree.X, PowerUpSizeThree.Y, HUDFont);
	GetTextSize(PowerUpPlayerFour, PowerUpSizeFour.X, PowerUpSizeFour.Y, HUDFont);

	//We Draw the Player's Current Points or Score on the top of the screen, Centered on the X
	DrawText(CurrentPointString1, FColor::Red, 0, ScreenDimensions.Y - ScoreSize1.Y, HUDFont);
	DrawText(PowerUpPlayerOne, FColor::Red, ScoreSize1.X + 10, ScreenDimensions.Y - PowerUpSizeOne.Y, HUDFont);

	DrawText(CurrentPointString2, FColor::Yellow, 0, 0, HUDFont);
	DrawText(PowerUpPlayerTwo, FColor::Yellow, ScoreSize2.X+ 10, 0, HUDFont);

	DrawText(CurrentPointString3, FColor::Blue, ScreenDimensions.X - ScoreSize3.X, 0, HUDFont);
	DrawText(PowerUpPlayerThree, FColor::Blue, ScreenDimensions.X - ScoreSize3.X - PowerUpSizeThree.X - 10, 0, HUDFont);

	DrawText(CurrentPointString4, FColor::Green, ScreenDimensions.X - ScoreSize4.X, ScreenDimensions.Y - ScoreSize4.Y, HUDFont);
	DrawText(PowerUpPlayerFour, FColor::Green, ScreenDimensions.X - ScoreSize4.X - PowerUpSizeFour.X - 10, ScreenDimensions.Y - PowerUpSizeFour.Y, HUDFont);

	ABouncerBallGameMode* BouncerBallGameMode = Cast<ABouncerBallGameMode>(UGameplayStatics::GetGameMode(this));
}


