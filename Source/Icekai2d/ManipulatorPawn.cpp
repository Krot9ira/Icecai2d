// Fill out your copyright notice in the Description page of Project Settings.


#include "ManipulatorPawn.h"






// Sets default values
AManipulatorPawn::AManipulatorPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AManipulatorPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AManipulatorPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AManipulatorPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


UFUNCTION(BlueprintCallable)
//Say controlled character where to go
void AManipulatorPawn::SetMovementPoint()
{
	FHitResult Hit;
	
	
	if (GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursorByChannel(TraceTypeQuery1, false, Hit) && ControlledCharacterRef)
	{
		if (Cast<ABaseCharacter>(Hit.GetActor()) || Cast<ABaseInteractableCPP>(Hit.GetActor()))
		{
			ABaseAIController* AIController = Cast<ABaseAIController>(ControlledCharacterRef->GetController());
				if (AIController)
				{
					AIController->GetBlackboardComponent()->SetValueAsObject(BBK_NavPoint, Hit.GetActor());
				}
		}
		else if (NavigationPointRef)
		{
			
			ABaseAIController* AIController = Cast<ABaseAIController>(ControlledCharacterRef->GetController());
			if (AIController)
			{
				NavigationPointRef->SetActorLocation(Hit.Location);
				AIController->GetBlackboardComponent()->SetValueAsObject(BBK_NavPoint, NavigationPointRef);
				NavigationPointRef->Blumps();

			}
		}
		else
		{
			ABaseAIController* AIController = Cast<ABaseAIController>(ControlledCharacterRef->GetController());
			if (AIController) 
			{
				FActorSpawnParameters SpawnParametrs;
				NavigationPointRef = GetWorld()->SpawnActor<ANavigationPoint>(NavigationPointToSpawn, Hit.Location, FRotator(0, 0, 0), SpawnParametrs);
				AIController->GetBlackboardComponent()->SetValueAsObject(BBK_NavPoint, NavigationPointRef);
				NavigationPointRef->Blumps();
			}
			
		}

	}
	
}
