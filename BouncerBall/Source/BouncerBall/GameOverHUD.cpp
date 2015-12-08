#include "BouncerBall.h"
#include "GameOverHUD.h"

#include "BouncerBallGameMode.h"
#include "BouncerPlayer.h"
#include "BouncerPlayerState.h"
#include "Kismet/GameplayStatics.h"



AGameOverHUD::AGameOverHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//use the RobotoDisanceField font from the engine
	static ConstructorHelpers::FObjectFinder<UFont>HUDFontOB(TEXT("/Game/Fonts/COPRGTB"));
	HUDFont = (UFont*)HUDFontOB.Object;
}

void AGameOverHUD::DrawHUD()
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

	int32 highScore;
	int32 highPlayer;

	FString CurrentPointString1 = "Player 1: ";
	FString CurrentPointString2 = "Player 2: ";
	FString CurrentPointString3 = "Player 3: ";
	FString CurrentPointString4 = "Player 4: ";

	FString Title = "Final Scores: ";
	FString RestartText = "Press R or Back to Restart.";

	//Get Scores and sort
	APlayerController* PlayerController1 = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerController1) {
		ABouncerPlayerState* PlayerState1 = Cast<ABouncerPlayerState>(PlayerController1->PlayerState);
		CurrentPointString1 += FString::Printf(TEXT("%d"), FMath::Abs(PlayerState1->RealScore));
		highScore = PlayerState1->RealScore;
		highPlayer = 1;
	}

	APlayerController* PlayerController2 = UGameplayStatics::GetPlayerController(GetWorld(), 1);
	if (PlayerController2) {
		ABouncerPlayerState* PlayerState2 = Cast<ABouncerPlayerState>(PlayerController2->PlayerState);
		CurrentPointString2 += FString::Printf(TEXT("%d"), FMath::Abs(PlayerState2->RealScore));
		if (PlayerState2->RealScore > highScore) {
			highScore = PlayerState2->RealScore;
			highPlayer = 2;
		}
	}

	APlayerController* PlayerController3 = UGameplayStatics::GetPlayerController(GetWorld(), 2);
	if (PlayerController3) {
		ABouncerPlayerState* PlayerState3 = Cast<ABouncerPlayerState>(PlayerController3->PlayerState);
		CurrentPointString3 += FString::Printf(TEXT("%d"), FMath::Abs(PlayerState3->RealScore));
		if (PlayerState3->RealScore > highScore) {
			highScore = PlayerState3->RealScore;
			highPlayer = 3;
		}
	}

	APlayerController* PlayerController4 = UGameplayStatics::GetPlayerController(GetWorld(), 3);
	if (PlayerController4) {
		ABouncerPlayerState* PlayerState4 = Cast<ABouncerPlayerState>(PlayerController4->PlayerState);
		CurrentPointString4 += FString::Printf(TEXT("%d"), FMath::Abs(PlayerState4->RealScore));
		if (PlayerState4->RealScore > highScore) {
			highScore = PlayerState4->RealScore;
			highPlayer = 4;
		}
	}


	//The dimensions 2D of the CurrentPointString
	FVector2D ScoreSize, ScoreSize1, ScoreSize2, ScoreSize3, ScoreSize4, TimeTextSize, TitleSize, RestartSize;
	GetTextSize(Title, TitleSize.X, TitleSize.Y, HUDFont);
	GetTextSize(RestartText, RestartSize.X, RestartSize.Y, HUDFont);
	GetTextSize(CurrentPointString1, ScoreSize1.X, ScoreSize1.Y, HUDFont, (highPlayer == 1) ? 2 : 1);
	GetTextSize(CurrentPointString2, ScoreSize2.X, ScoreSize2.Y, HUDFont, (highPlayer == 2) ? 2 : 1);
	GetTextSize(CurrentPointString3, ScoreSize3.X, ScoreSize3.Y, HUDFont, (highPlayer == 3) ? 2 : 1);
	GetTextSize(CurrentPointString4, ScoreSize4.X, ScoreSize4.Y, HUDFont, (highPlayer == 4) ? 2 : 1);

	//Draw Title && Instructions
	DrawText(Title, FColor::White, (ScreenDimensions.X - TitleSize.X) / 2, 0, HUDFont);
	DrawText(RestartText, FColor::White, 0, ScreenDimensions.Y - RestartSize.Y, HUDFont);

	//Draw Players Scores & arrange by highest to lowest
	DrawText(CurrentPointString1, FColor::Red, (ScreenDimensions.X - ScoreSize1.X) / 2, 0 + (ScreenDimensions.Y / 4) - ScoreSize1.Y, HUDFont, (highPlayer == 1) ? 2 : 1);

	DrawText(CurrentPointString2, FColor::Yellow, (ScreenDimensions.X - ScoreSize2.X) / 2, 0 + ((ScreenDimensions.Y / 4) * 2) - ScoreSize2.Y, HUDFont, (highPlayer == 2) ? 2 : 1);

	DrawText(CurrentPointString3, FColor::Blue, (ScreenDimensions.X - ScoreSize3.X) / 2, 0 + ((ScreenDimensions.Y / 4) * 3) - ScoreSize3.Y, HUDFont, (highPlayer == 3) ? 2 : 1);

	DrawText(CurrentPointString4, FColor::Green, (ScreenDimensions.X - ScoreSize4.X) / 2, ScreenDimensions.Y - ScoreSize4.Y, HUDFont, (highPlayer == 4) ? 2 : 1);

	ABouncerBallGameMode* BouncerBallGameMode = Cast<ABouncerBallGameMode>(UGameplayStatics::GetGameMode(this));
}