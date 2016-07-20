// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"



ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	if (GetPawn()) {
		ATank* tank = GetControlledTank();
		FString name = tank->GetName();
		//UE_LOG(LogTemp, Warning, TEXT("Player Tank is %s"), *name);
	}
	else {
		//UE_LOG(LogTemp, Error, TEXT("No possessed pawn found."));
	}
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) {
		return;
	}
	
	FVector HitLocation; //OUT parameter
	if (GetSiteRayHitLocation(HitLocation)) {// has "side-effect" of ray tracing
		GetControlledTank()->AimAt(HitLocation);
	}
	
}


void ATankPlayerController::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);
	AimTowardsCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("Tick %f seconds"), DeltaSeconds);
}


//get world location of linetrace through crosshair, true if its landscape
bool ATankPlayerController::GetSiteRayHitLocation(FVector& HitLocation) const {
	//Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	
	UPROPERTY(EditAnywhere) 
		float CrossHairXLocation = 0.5;
	
	UPROPERTY(EditAnywhere) 
		float CrossHairYLocation = 0.333;
	
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.0f;


	FVector2D ScreenLocation = FVector2D(CrossHairXLocation*ViewportSizeX, CrossHairYLocation*ViewportSizeY);
	//UE_LOG(LogTemp, Warning, TEXT("crossHair: %s"), *ScreenLocation.ToString());


	//Deproject screen position of the crosshair to a world direction
	FVector CameraLocation, WorldDirection;
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraLocation, WorldDirection)) {
		//Line trace along world direction up to a maximum range
		FHitResult Hit;
		FVector Start;
		FVector End;
		ECollisionChannel TraceChannel = ECC_Visibility;
		FCollisionQueryParams Params;
		FCollisionResponseParams ResponseParam;

		Start = CameraLocation;
		End = CameraLocation + WorldDirection * LineTraceRange;
		
		if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, TraceChannel, Params, ResponseParam)) {
			HitLocation = Hit.Location;
			return true;
		}
		HitLocation = FVector(0.0f);
	}


	return false;
}
