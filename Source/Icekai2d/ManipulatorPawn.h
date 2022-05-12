// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <Icekai2d/BaseCharacter.h>
#include "Engine/World.h"
#include <Icekai2d/NavigationPoint.h>
#include <Icekai2d/BaseInteractableCPP.h>
#include <Icekai2d/BaseAIController.h>
#include "ManipulatorPawn.generated.h"




UCLASS()
class ICEKAI2D_API AManipulatorPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AManipulatorPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(BlueprintReadWrite, Category="Character")
		ABaseCharacter* ControlledCharacterRef;
	UPROPERTY(BlueprintReadWrite, Category="Character")
		ANavigationPoint* NavigationPointRef;
	UPROPERTY(BlueprintReadWrite, Category = "Character")
		FName BBK_NavPoint;
	UPROPERTY(BlueprintReadWrite, Category = "Character")
	TSubclassOf<ANavigationPoint> NavigationPointToSpawn;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintCallable)
	void SetMovementPoint();
	
};
