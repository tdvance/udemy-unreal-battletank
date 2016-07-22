// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"



// Sets default values for this component's properties
UTankTurret::UTankTurret()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankTurret::RotateTurret(float RelativeSpeed) {
	auto AzimuthChange = MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Azimuth = RelativeRotation.Yaw + AzimuthChange;
	SetRelativeRotation(FRotator(0, Azimuth, 0));
}

// Called when the game starts
void UTankTurret::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankTurret::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

