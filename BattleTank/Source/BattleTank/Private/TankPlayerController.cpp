// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("TankPlayerController not possesing a tank."));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController possesing %s."), *(ControlledTank->GetName()));
	}	
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if(!GetControlledTank())
	{
		UE_LOG(LogTemp, Error, TEXT("TankPlayerController not possesing a tank."));
		return;
	}

	// Aiming code here
	
	return;
}



