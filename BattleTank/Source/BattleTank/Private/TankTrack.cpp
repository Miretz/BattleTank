// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{
	//TODO clamp actual throttle value
	
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *Name, Throttle);
}
