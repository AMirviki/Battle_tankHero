// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank_Hero.generated.h"

UCLASS()
class BATTLETANK_API ATank_Hero : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank_Hero();
	void AimAt(FVector Hitlocation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
