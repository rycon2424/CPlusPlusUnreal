// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingObject.h"
#include "Obstacle.generated.h"

UCLASS()
class CPLUSPLUS_API AObstacle : public AMovingObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacle();

	UPROPERTY(EditAnywhere, Category = "Obstacle")
	float obstacleSpeed = -1;

	UPROPERTY(EditAnywhere, Category = "Obstacle")
	float strafingSpeed = 1;

	UPROPERTY(EditAnywhere, Category = "Obstacle")
	bool goingLeft;

	UPROPERTY(EditAnywhere, Category = "Obstacle")
	float fallDownSpeed = 1;

	FVector acceleration;

	UPROPERTY(EditAnywhere, Category = "Obstacle")
	UStaticMeshComponent* mesh;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
