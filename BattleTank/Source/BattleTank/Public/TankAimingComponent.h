// Copyright Miretz 2016

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Enum state of the barrel
UENUM()
enum class EFiringState : uint8
{
	Locked,
	Aiming,
	Reloading
};


// Forward Declaration
class UTankBarrel; 
class UTankTurret;
class AProjectile;

// Aiming component of the Tank
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Fire")
	void Fire();

protected:

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

private:

	// Sets default values for this component's properties
	UTankAimingComponent();

	void MoveBarrelTowards(FVector);

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	bool IsBarrelMoving();

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	FVector AimDirection;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000.0f; // value of 1000 m/s

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	double LastFireTime = 0.0;
	
};
