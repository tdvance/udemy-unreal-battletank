// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::ElevateBarrel(float RelativeSpeed) {


	//scale delta pitch/roll/yaw for realistic barrel speed
	//adjust barrel by this delta amount
	//UE_LOG(LogTemp, Warning, TEXT("%f: Barrel-elevate called at speed %f"), Time, RelativeSpeed)

	auto ElevationChange = FMath::Clamp<float>(RelativeSpeed, -1, 1) * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	SetRelativeRotation(FRotator(FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees), 0, 0));
}



