// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TopDownPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNUTILITIES_API ATopDownPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:	
	ATopDownPlayerController();
protected:
	virtual void setupInputComponent() override;
};
