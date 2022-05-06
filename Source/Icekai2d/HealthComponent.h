// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ICEKAI2D_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnyWhere)
		int32 Health;
	UPROPERTY(EditAnyWhere)
		int32 MaxHealth;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Health regulation function

	UFUNCTION(BlueprintCallable)
		void RemoveHealth(int32 Damage)
	{
		Health -= Damage;
	}

	UFUNCTION(BlueprintCallable)
		void AddHealth(int32 Restore)
	{
		Health += Restore;
	}

	UFUNCTION(BlueprintCallable)
		int32 GetHealth()
	{
		return Health;
	}
};
