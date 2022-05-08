// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

UCLASS()
class ICEKAI2D_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();

protected:
	//base parametrs for weapon
	UPROPERTY(EditAnyWhere, Category = "Parametrs")
		int32 Damage;
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Parametrs")
		int32 AttackSpeed;
	UPROPERTY(EditAnyWhere, Category = "Parametrs")
		int32 Range;
	UPROPERTY(EditAnywhere, Category = "Parametrs")
		TArray<AActor*> DamagedActors;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void Attack(AActor* Target);
	UFUNCTION(BlueprintCallable)
		void ResetDamagedActors();
	UFUNCTION(BlueprintCallable)
		void UpdateDamage(int32 NewDamage);
	UFUNCTION(BlueprintCallable)
		int32 GetDamage();
	UFUNCTION(BlueprintCallable)
		int32 GetRange();
	

};
