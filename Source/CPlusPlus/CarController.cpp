// Fill out your copyright notice in the Description page of Project Settings.


#include "CarController.h"
#include "Components/StaticMeshComponent.h"
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

	movingDirection = FVector(0.f);
}

// Called when the game starts or when spawned
void ACarController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACarController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	mesh->AddLocalOffset(movingDirection * speedMultiplyer * DeltaTime);
}

// Called to bind functionality to input
void ACarController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Vertical", this, &ACarController::VerticalInput);
	PlayerInputComponent->BindAxis("Horizontal", this, &ACarController::HorizontalInput);
}

void ACarController::HorizontalInput(float axisX)
{
	movingDirection += FVector(0, axisX, 0);
}

void ACarController::VerticalInput(float axisY)
{
	movingDirection += FVector(axisY, 0, 0);
}
