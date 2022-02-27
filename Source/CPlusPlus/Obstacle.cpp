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
	int direction = FMath::RandRange(0, 1);
	if (direction == 0)
	{
		goingLeft = false;
	}
	else
	{
		goingLeft = true;
	}
	velocityspeed = FMath::RandRange(3, 8);
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (goingLeft)
	{
		if (GetActorLocation().Y <= -450)
		{
			goingLeft = false;
			velocity.Y = 0;
		}
		acceleration = FVector(obstacleSpeed, -strafingSpeed, 0);
	}
	else
	{
		if (GetActorLocation().Y >= 950)
		{
			goingLeft = true;
			velocity.Y = 0;
		}
		acceleration = FVector(obstacleSpeed, strafingSpeed, 0);
	}

	acceleration += friction * velocity; // Friction

	velocity += DeltaTime * acceleration * velocityspeed; // Set velocity

	acceleration = FVector(0);

	mesh->AddLocalOffset(velocity);

	if (GetActorLocation().X <= -400)
	{
		Destroy();
	}
}

