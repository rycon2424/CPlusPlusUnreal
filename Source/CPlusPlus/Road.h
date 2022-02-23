// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Road.generated.h"

UCLASS()
class CPLUSPLUS_API ARoad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARoad();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, Category = "Road Settings")
	FVector startPosition;

	UPROPERTY(EditAnywhere, Category = "Road Settings")
	FVector movingDirection;

	UPROPERTY(EditAnywhere, Category = "Road Settings")
	float maxDistance = 2.f;

	UPROPERTY(EditAnywhere, Category = "Road Settings")
	float speedMultiplyer = 3.f;

};
