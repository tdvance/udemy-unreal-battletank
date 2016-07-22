// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet) {
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet) {
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(APawn* tank, FVector HitLocation, float LaunchSpeed) {
	if (!Barrel || !Turret) {
		return;
	}
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	
	// Calculate the OutLaunchVelocity
	if (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, HitLocation, 
		LaunchSpeed, false, 5.0, 0.0, ESuggestProjVelocityTraceOption::DoNotTrace)) {
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);

	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {
	//find 3d angle from current barrel direction to aim direction
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator TurretRotator = Turret->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();

	//AimAsRotator = FRotator(4, 130, 0);//temporary for testing

	//find delta pitch/roll/yaw to move barrel direction toward aim direction
//		FRotator DeltaRotator = AimAsRotator - BarrelRotator;
	float DeltaPitch = AimAsRotator.Pitch - BarrelRotator.Pitch;
	float DeltaYaw = AimAsRotator.Yaw - TurretRotator.Yaw;
	if (DeltaYaw > 180) {
		DeltaYaw -= 360;
	}
	if (DeltaYaw < -180) {
		DeltaYaw += 360;
	}


	Barrel->ElevateBarrel(DeltaPitch); 
	Turret->RotateTurret(DeltaYaw);
	/*UE_LOG(LogTemp, Warning, TEXT("Moving aim from: p=%f y=%f to: p=%f y=%f delta: p=%f y=%f"),
		BarrelRotator.Pitch, TurretRotator.Yaw, AimAsRotator.Pitch, AimAsRotator.Yaw, DeltaPitch, DeltaYaw);*/

}
