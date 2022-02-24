// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MovingObject.generated.h"

UCLASS()
class CPLUSPLUS_API AMovingObject : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMovingObject();

	UPROPERTY(EditAnywhere, Category = "Moving Object")
	float velocityspeed = 5.f;
	UPROPERTY(EditAnywhere, Category = "Moving Object")
	float friction = -0.1f;
	UPROPERTY(VisibleAnywhere, Category = "Moving Object")
	FVector velocity = FVector(0);

public:
	FVector CalculateSpeed();

};
