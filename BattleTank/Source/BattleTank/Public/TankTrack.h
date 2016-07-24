// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set driving force, and to apply forces to the tank.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, CAtegory = Input)
		void SetThrottle(float Throttle);	
	//Max force per track in Newtons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 3 * 48000 * 2.2; //tank mass times 2.2 pounds per 
						//kilogram times 3 m/sec sqared acceleartion to get 0-60 in 10 seconds.
	
	
};
