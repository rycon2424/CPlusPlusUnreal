// Fill out your copyright notice in the Description page of Project Settings.


#include "CarController.h"
#include "Components/StaticMeshComponent.h"
#include "Obstacle.h"
#include "Camera/CameraComponent.h"

// Sets default values
ACarController::ACarController()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	rootMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootMesh"));
	SetRootComponent(rootMesh);

	followCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	acceleration = FVector(0.f);

	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void ACarController::BeginPlay()
{
	Super::BeginPlay();
	mesh->OnComponentHit.AddDynamic(this, &ACarController::OnComponentHit);
}

// Called every frame
void ACarController::Tick(float DeltaTime)
{
	if (gameOver)
	{
		mesh->AddWorldOffset(velocity);
		return;
	}
	Super::Tick(DeltaTime);

	acceleration += friction * velocity; // Friction

	velocity += DeltaTime * acceleration * velocityspeed; // Set velocity

	//UE_LOG(LogTemp, Warning, TEXT("Velocity = %s"), *velocity.ToString()); // Debug
	//UE_LOG(LogTemp, Warning, TEXT("Acceleration = %s"), *acceleration.ToString()); // Debug
	//UE_LOG(LogTemp, Warning, TEXT("time = %f"), GetWorld()->GetTimeSeconds());

	if (GetWorld()->GetTimeSeconds() > timerTime)
	{
		timerTime += 5;
		score += 50;
	}
	acceleration = FVector(0);

	mesh->AddWorldOffset(velocity);
}

// Called to bind functionality to input
void ACarController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Vertical", this, &ACarController::VerticalInput);
	PlayerInputComponent->BindAxis("Horizontal", this, &ACarController::HorizontalInput);
}

void ACarController::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& hit)
{
	if (gameOver)
	{
		return;
	}
	if (OtherActor->GetClass()->IsChildOf(AObstacle::StaticClass()))
	{
		OtherActor->Destroy();
		lives--;
		if (lives < 1)
		{
			GameOver();
		}
	}
}

void ACarController::GameOver()
{
	gameOverText = "Game Over";
	scoreText = "FinalScore:";
	endScore = FString::FromInt(score);
	acceleration = FVector(0);
	velocity = FVector(0);
	gameOver = true;
}

void ACarController::HorizontalInput(float axisX)
{
	acceleration.Y = axisX * XMultiplyer;
}

void ACarController::VerticalInput(float axisY)
{
	acceleration.X = axisY * YMultiplyer;
}