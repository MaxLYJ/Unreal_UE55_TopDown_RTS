// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerPawn.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h" // Ensure this header is included for UEnhancedInputComponent
#include "InputActionValue.h"
#include "GameFramework/FloatingPawnMovement.h"

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

	//Create a floating pawn movement component
	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));
}

// Called when the game starts or when spawned
void AControllerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AControllerPawn::Move(const FInputActionValue& Value)
{
	//Get the movement input from the action value
	const FVector2D MovementInput = Value.Get<FVector2D>();
	if (Controller)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		//•	Creates a new rotation that only uses the yaw (left/right), ignoring pitch and roll. This keeps movement parallel to the ground.
		const FRotator YawRotation = FRotator(0, Rotation.Yaw, 0);

		//FRotationMatrix(YawRotation) convert an FRotator into a matrix
		//GetUnitAxis(EAxis::X) give me the X axis of this rotated coordinate system, and unify it.
		//EAxis means an enum type, and use scope resolution operator :: to access members from it.
		//Why not Axis.X or EAxix->X? 
		//•	EAxis.X would be used if EAxis was a struct or class instance (which it is not).
		//• EAxis->X would be used if EAxis was a pointer to a struct or class (which it is not).
		const FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(Forward, MovementInput.Y);
		AddMovementInput(Right, MovementInput.X);
	}
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

	//Check if Cast to enhanced input component success, then bind MoveAction to the move function.
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (MoveAction)
		{
			//Bind the MoveAction to the Move function
			EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AControllerPawn::Move);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("MoveAction is not set in AControllerPawn"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerInputComponent is not an EnhancedInputComponent"));

        // Fix the error by ensuring the correct namespace or class is used
        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AControllerPawn::Move);
	}
}

