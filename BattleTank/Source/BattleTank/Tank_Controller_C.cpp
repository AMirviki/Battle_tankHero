// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank_Controller_C.h"

void ATank_Controller_C::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );

	AimTowardCrossHair();
	
}

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
		GetControlledTank()->AimAt(Hitlocation);
	}

	

	//get World Location if linetrace through crosshair
	//if hits the ladnscape 
	//Tell Controlled Tank to aim at This Point
}


// Get World location of linetrace through crosshair , true if Hits Landscape
bool ATank_Controller_C::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Find the crosshair position in pixel Coordinates

	int32 ViewportSizeX, ViewportSizeY;

	GetViewportSize(ViewportSizeX, ViewportSizeY);

	auto ScreenLocation = FVector2D (ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	
	FVector LookDirection;

	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		// Line-Trace along that lookDirection , and see what we hit (up to max Range)
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	

	
	return true;
}
// why we put const on the last ? cause we dont want change any variable members
bool ATank_Controller_C::GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const
{
	FHitResult Hitresult;
	auto startlocation = PlayerCameraManager->GetCameraLocation();
	auto endlocation = startlocation + (LookDirection * linetracerange);
	if (GetWorld()->LineTraceSingleByChannel(Hitresult, startlocation, endlocation, ECollisionChannel::ECC_Visibility)
		)
	{
		//sit Hit location
		HitLocation = Hitresult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false; //line trace	Didn't succeed
}
bool ATank_Controller_C::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{

	FVector cameraworldlocation; //to be Discard
	
	return DeprojectScreenPositionToWorld(

		ScreenLocation.X,
		ScreenLocation.Y,
		cameraworldlocation,
		LookDirection

		
	);
	
}


