// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"

// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MovingMesh"));
	SetRootComponent(mesh);
}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	acceleration = FVector(obstacleSpeed, 0, 0);

	acceleration += friction * velocity; // Friction

	velocity += DeltaTime * acceleration * velocityspeed; // Set velocity

	acceleration = FVector(0);

	mesh->AddLocalOffset(velocity);
}

