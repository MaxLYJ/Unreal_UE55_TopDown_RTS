// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerPawn.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AControllerPawn::AControllerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create capsule component
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	RootComponent = CapsuleComponent;
	//set the capsule hidden in game to false.
	CapsuleComponent->SetHiddenInGame(false);

	//Create camera components
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CharacterCameraComponent"));
	//set camera to orthographic mode
	CameraComponent->SetProjectionMode(ECameraProjectionMode::Orthographic);

	//Create spring arm component
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	//Set the spring arm length to 418
	SpringArmComponent->TargetArmLength = 418.0f;
	//Why in editor, this rotator is (0.0f, -45.0f, 0.0f), But in code we need to write it as (-45.0f, 0.0f, 0.0f)?
	//FRotator(Pitch, Yaw, Roll), so it as actually equal to (Y, Z, X) in the editor.
	SpringArmComponent->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));

	//Set the spring arm as the root component
	SpringArmComponent->SetupAttachment(RootComponent);
	//Attach the CharacterCameraComponet to the SpringArm
	CameraComponent->SetupAttachment(SpringArmComponent);
}

// Called when the game starts or when spawned
void AControllerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AControllerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AControllerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

