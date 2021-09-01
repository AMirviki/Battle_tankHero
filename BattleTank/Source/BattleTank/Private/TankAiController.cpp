// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ai Controller Cant Find Player Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Find Player: %S"), *(PlayerTank->GetName()));
	}

}


ATank_Hero* ATankAiController::GetControlledTank() const
{
	return Cast<ATank_Hero>(GetPawn());
	
}
ATank_Hero* ATankAiController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		return nullptr;
	}
	return Cast<ATank_Hero>(PlayerPawn);

}
