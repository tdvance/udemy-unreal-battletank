// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"
#include "Tank.h"




void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	
	
}



void ATankAIController::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);
	ATank* ControlledTank = Cast<ATank>(GetPawn());
	if (!ControlledTank) {
		return;
	}

	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) {
		UE_LOG(LogTemp, Error, TEXT("No player controller found."));
		return;
	}
	ATank* PlayerTank = Cast<ATank>(PlayerPawn);
	
	FVector HitLocation = PlayerTank->GetActorLocation();
	ControlledTank->AimAt(HitLocation);
	ControlledTank->Fire();
}	
