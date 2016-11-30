// Copyright Miretz 2016

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;

	virtual void Tick(float) override;

	void AimTowardsPlayer();

	// How close can the AI tank get to the player
	float AcceptanceRadius = 3000.0f;
};
