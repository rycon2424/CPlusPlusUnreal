// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MovingObject.h"
#include "CarController.generated.h"

UCLASS()
class CPLUSPLUS_API ACarController : public AMovingObject
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACarController();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HUD")
	bool gameOver;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HUD")
	int lives = 3;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HUD")
	int score = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HUD")
	FString gameOverText = "";

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HUD")
	FString scoreText = "";

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HUD")
	FString endScore = "";

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& hit);

private:

	UPROPERTY(VisibleAnywhere, Category = "CarController")
	class UStaticMeshComponent* rootMesh;

	UPROPERTY(VisibleAnywhere, Category = "CarController")
	class UStaticMeshComponent* mesh;

	UPROPERTY(VisibleAnywhere, Category = "CarController")
	class UCameraComponent* followCamera;

	UPROPERTY(VisibleAnywhere, Category = "CarController")
	FVector acceleration;

	UPROPERTY(EditAnywhere, Category = "CarController")
	float XMultiplyer = 1;

	UPROPERTY(EditAnywhere, Category = "CarController")
	float YMultiplyer = 1;

	float timerTime = 5;

private:

	void HorizontalInput(float axisX);

	void VerticalInput(float axisY);

	void GameOver();

};
