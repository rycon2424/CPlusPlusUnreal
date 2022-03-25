// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"

// Sets default values
AGameManager::AGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameManager::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(spawnTimer, this, &AGameManager::SpawnRandomCars, spawnFrequency, true, timeBeforeSpawning);
}

// Called every frame
void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGameManager::SpawnRandomCars()
{
	FVector location = spawnPositions[FMath::RandRange(0, spawnPositions.Num() - 1)];
	int carNumber = FMath::RandRange(0, spawnActor.Num() - 1);
	//UE_LOG(LogTemp, Warning, TEXT("Spawnable  = %d"), spawnActor.Num());
	FRotator rotation = FRotator(0);
	GetWorld()->SpawnActor<AActor>(spawnActor[carNumber], location, rotation);
}

