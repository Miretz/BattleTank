// Copyright Miretz 2016

#include "BattleTank.h"
#include "TankAIController.h"
#include "TankAimingComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsPlayer();
}

void ATankAIController::AimTowardsPlayer()
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent) || !ensure(PlayerTank)) { return; }

	// Move towards player tank
	MoveToActor(PlayerTank, AcceptanceRadius);
		
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	if (AimingComponent->GetFiringState() == EFiringState::Locked)
	{
		AimingComponent->Fire(); // TODO limit firing rate
	}
}
