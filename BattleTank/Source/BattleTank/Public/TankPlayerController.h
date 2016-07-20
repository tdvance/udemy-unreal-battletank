// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // must be last include


/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

	//Return an OUT parameter, true if hit landscape
	bool GetSiteRayHitLocation(FVector& HitLocation) const;


public:
	ATank* GetControlledTank() const;
	void AimTowardsCrosshair();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
};

