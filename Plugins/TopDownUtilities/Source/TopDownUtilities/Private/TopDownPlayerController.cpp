// Fill out your copyright notice in the Description page of Project Settings.


#include "TopDownPlayerController.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

ATopDownPlayerController::ATopDownPlayerController()
{
	//show mouse cursor
	bShowMouseCursor = true;
}

void ATopDownPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (!DefaultInputMappingContext)
	{
		UE_LOG(LogTemp, Warning, TEXT("DeaultInputMappingContext is not set in ATopDownPlayerController"));
		return;
	}
	//Gets EnhancedInput Subsystem from the local player, prepare for edit input mapping contexts at runtime.
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	
	if (Subsystem)
	{
		//Add the default input mapping context to the subsystem
		Subsystem->AddMappingContext(DefaultInputMappingContext, 0);
		UE_LOG(LogTemp, Warning, TEXT("EnhancedInputLocalPlayerSubsystem added"));

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("EnhancedInputLocalPlayerSubsystem not found"));
	}

}
