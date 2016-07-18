// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"



ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	if (GetPawn()) {
		ATank* tank = GetControlledTank();
		FString name = tank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Player Tank is %s"), *name);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("No possessed pawn found."));
	}
}
