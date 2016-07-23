// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//-1 -> max downward movement
	//+1 -> max upward movement
	void ElevateBarrel(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxDegreesPerSecond = 10; //sensible default
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxElevationDegrees = 35; //sensible default
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MinElevationDegrees = 0; //sensible default
};
