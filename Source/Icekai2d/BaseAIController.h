// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BaseCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BaseAIController.generated.h"

/**
 * 
 */
UCLASS()
class ICEKAI2D_API ABaseAIController : public AAIController
{
	GENERATED_BODY()
public:
	ABaseAIController(const FObjectInitializer& ObjectInitializer);

	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY(transient)
		class UBehaviorTreeComponent* BTC;
	UPROPERTY(transient)
		class UBlackboardComponent* BBC;

	//BB key Ids
	uint8 EnemyKeyId;
	uint8 NavPoint;
	
};
