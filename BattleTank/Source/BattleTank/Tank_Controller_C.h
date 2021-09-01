// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Tank_Hero.h"
#include "GameFramework/PlayerController.h"
#include "Tank_Controller_C.generated.h" //must be the Last Include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATank_Controller_C : public APlayerController
{
	GENERATED_BODY()

public :
	virtual void Tick(float DeltaTime) override;

	ATank_Hero* GetControlledTank() const;

	virtual void BeginPlay() override;
	// Start The Tank Moving The Barrel So that A Shot Would it where 
	// the crosshair intersects the world

	void AimTowardCrossHair();
	bool GetSightRayHitLocation(FVector&OutHitLocation ) const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;
};
