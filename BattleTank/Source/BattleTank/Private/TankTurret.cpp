// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"

void UTankTurret::RotateTurret(float degrees) {
	auto AzimuthChange = MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	degrees = FMath::Clamp<float>(degrees, -AzimuthChange, AzimuthChange);
	
	auto Azimuth = RelativeRotation.Yaw + degrees;
	SetRelativeRotation(FRotator(0, Azimuth, 0));
}
