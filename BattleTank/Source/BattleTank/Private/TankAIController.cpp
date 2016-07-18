// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"




ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));
	if (GetPawn()) {
		ATank* tank = GetControlledTank();
		FString name = tank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("AI Tank is %s"), *name);
		tank = GetPlayerTank();
		if (tank) {
			FString pcname = tank->GetName();
			UE_LOG(LogTemp, Warning, TEXT("AI Tank %s found player controller tank %s"), *name, *pcname);
		}
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("No possessed pawn found."));
	}
	
}

ATank* ATankAIController::GetPlayerTank() const {
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) {
		UE_LOG(LogTemp, Error, TEXT("No player controller found."));
	}
	ATank* tank = Cast<ATank>(PlayerPawn);
	return tank;
}
