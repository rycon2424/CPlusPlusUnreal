// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameManager.generated.h"

UCLASS()
class CPLUSPLUS_API AGameManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameManager();

	UPROPERTY(EditAnywhere, Category = "GameManager")
	TArray<TSubclassOf<AActor>> spawnActor;

	UPROPERTY(EditAnywhere, Category = "GameManager")
	TArray<FVector> spawnPositions;

	UPROPERTY(EditAnywhere, Category = "GameManager")
	float spawnFrequency = 5;

	UPROPERTY(EditAnywhere, Category = "GameManager")
	float timeBeforeSpawning = 2;

	FTimerHandle spawnTimer;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SpawnRandomCars();

};
