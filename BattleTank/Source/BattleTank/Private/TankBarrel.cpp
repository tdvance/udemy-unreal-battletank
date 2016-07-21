// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::ElevateBarrel(float RelativeSpeed) {


	//scale delta pitch/roll/yaw for realistic barrel speed
	//adjust barrel by this delta amount
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Barrel-elevate called at speed %f"), Time, RelativeSpeed)
}



