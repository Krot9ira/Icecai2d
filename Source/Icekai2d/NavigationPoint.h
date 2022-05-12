// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NavigationPoint.generated.h"

UCLASS()
class ICEKAI2D_API ANavigationPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANavigationPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//visual effect for point
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void Blumps();

};
