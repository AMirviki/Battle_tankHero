// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank_Hero.h"

// Sets default values
ATank_Hero::ATank_Hero()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}



// Called when the game starts or when spawned
void ATank_Hero::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank_Hero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank_Hero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
void ATank_Hero::AimAt(FVector Hitlocation)
{
	auto ournametank = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Aiming at % s"), *ournametank, *Hitlocation.ToString());
}

