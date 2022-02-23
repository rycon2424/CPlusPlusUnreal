// Fill out your copyright notice in the Description page of Project Settings.


#include "Road.h"

// Sets default values
ARoad::ARoad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARoad::BeginPlay()
{
	Super::BeginPlay();
	startPosition = GetActorLocation();
}

// Called every frame
void ARoad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector currentLocation = GetActorLocation();
	if (currentLocation.X <= maxDistance)
	{
		SetActorLocation(startPosition);
	}
	AddActorWorldOffset(movingDirection * speedMultiplyer * DeltaTime);
}

