// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank_Controller_C.h"

void ATank_Controller_C::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller not Possessing Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Atank_player possessing Tank : %S"), *(ControlledTank->GetName()));
	}

}

void ATank_Controller_C::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
	AimTowardCrossHair();
	
}



ATank_Hero* ATank_Controller_C::GetControlledTank() const
{
	return Cast<ATank_Hero>(GetPawn());
	
}

void ATank_Controller_C::AimTowardCrossHair()
{
	if (!GetControlledTank())
	{
		return;
	}
	FVector Hitlocation; // Out Parameter
	if (GetSightRayHitLocation(Hitlocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look DIrection: % s"), *Hitlocation.ToString());
	}

	

	//get World Location if linetrace through crosshair
	//if hits the ladnscape 
	//Tell Controlled Tank to aim at This Point
}
bool ATank_Controller_C::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	
	return true;
}