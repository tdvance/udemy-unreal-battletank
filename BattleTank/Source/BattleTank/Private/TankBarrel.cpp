// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::ElevateBarrel(float DegreesPerSecond) {


	//scale delta pitch/roll/yaw for realistic barrel speed
	//adjust barrel by this delta amount
	UE_LOG(LogTemp, Warning, TEXT("Barrel-elevate called at speed %f"), DegreesPerSecond)
}



