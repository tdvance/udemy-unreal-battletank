// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::ElevateBarrel(float degrees) {


	//scale delta pitch/roll/yaw for realistic barrel speed
	//adjust barrel by this delta amount
	//UE_LOG(LogTemp, Warning, TEXT("%f: Barrel-elevate called at speed %f"), Time, RelativeSpeed)

	auto ElevationChange = MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	degrees = FMath::Clamp<float>(degrees, -ElevationChange, ElevationChange);
	SetRelativeRotation(FRotator(RelativeRotation.Pitch + degrees, 0, 0));
}



