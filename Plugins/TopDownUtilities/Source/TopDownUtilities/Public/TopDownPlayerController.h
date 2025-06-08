// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TopDownPlayerController.generated.h"

/**
 * 
 */


class UInputMappingContext;

UCLASS()
class TOPDOWNUTILITIES_API ATopDownPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:	
	ATopDownPlayerController();
	// Sets default values for this controller's properties. This property allows you to assign an input mapping context to your player controller in the editor or via Blueprints, making it easy to configure which set of input actions the controller should use. This is especially useful when using the Enhanced Input system in Unreal Engine.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultInputMappingContext;

protected:
	virtual void SetupInputComponent() override;
};
