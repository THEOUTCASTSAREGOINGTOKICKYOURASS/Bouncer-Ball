#pragma once

#include "GameFramework/HUD.h"
#include "GameOverHUD.generated.h"

/**
*
*/
UCLASS()
class BOUNCERBALL_API AGameOverHUD : public AHUD
{
	GENERATED_BODY()

		UPROPERTY()
		UFont* HUDFont;

	//Primary draw call for the HUD
	virtual void DrawHUD() override;

public:
	AGameOverHUD(const FObjectInitializer& ObjectInitializer);
};