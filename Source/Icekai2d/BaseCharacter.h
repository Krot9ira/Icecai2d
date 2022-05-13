// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <Icekai2d/HealthComponent.h>
#include <Icekai2d/StatsComponent.h>
#include "BaseCharacter.generated.h"


UCLASS()
class ICEKAI2D_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly)
		UHealthComponent* HealthComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UStatsComponent* StatsComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		class UBehaviorTree* TreeAsset;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void Dash();
};
