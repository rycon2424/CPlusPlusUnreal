// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CarController.generated.h"

UCLASS()
class CPLUSPLUS_API ACarController : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACarController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	class UStaticMeshComponent* rootMesh;

	UPROPERTY(VisibleAnywhere, Category = "CarController")
	class UStaticMeshComponent* mesh;

	UPROPERTY(VisibleAnywhere, Category = "CarController")
	class UCameraComponent* followCamera;

	UPROPERTY(VisibleAnywhere, Category = "CarController")
	FVector movingDirection;

	UPROPERTY(EditAnywhere, Category = "CarController")
	float speedMultiplyer = 3.f;

private:

	void HorizontalInput(float axisX);

	void VerticalInput(float axisY);

};
