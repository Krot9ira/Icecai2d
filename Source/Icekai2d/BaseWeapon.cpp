// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWeapon.h"

// Sets default values
ABaseWeapon::ABaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseWeapon::Attack(AActor* Target)
{
	if ((Target)&&(Target!= ABaseWeapon::GetOwner()))
	{
		Target->TakeDamage(Damage, FDamageEvent(), this->GetInstigatorController(), this);
		DamagedActors.Add(Target);
	}
	
}

void ABaseWeapon::ResetDamagedActors()
{
	DamagedActors.Empty(10);
}

void ABaseWeapon::UpdateDamage(int32 NewDamge)
{
	Damage = NewDamge;
}

int32 ABaseWeapon::GetDamage()
{
	return int32(Damage);
}

