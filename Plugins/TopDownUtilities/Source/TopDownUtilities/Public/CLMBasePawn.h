// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CLMBasePawn.generated.h"

class UCapsuleComponent;
class USkeletalMeshComponent;
class UFloatingPawnMovement;

UCLASS()
class TOPDOWNUTILITIES_API ACLMBasePawn : public APawn
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = Collision, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCapsuleComponent> CapsuleComponent;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = Pawn, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = Pawn, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UFloatingPawnMovement> FloatingPawnMovement;

public:
	// Sets default values for this pawn's properties
	ACLMBasePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
