// Copyright Epic Games, Inc. All Rights Reserved.

#include "RTS_DemoGameMode.h"
#include "RTS_DemoPlayerController.h"
#include "RTS_DemoCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARTS_DemoGameMode::ARTS_DemoGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ARTS_DemoPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}