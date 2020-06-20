// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "mPawn.generated.h"

UCLASS()
class MOONNIGHT_API AmPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AmPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	class USphereComponent* mSphere;
	class UCameraComponent* mCamera;
	class UStaticMeshComponent* mSphereMesh;

public:
	bool bTrottle = false;
	bool bBreak = false;
	bool bHandBreak = false;
	bool bTurnLeft = false;
	bool bTurnRight = false;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float MaxSpeed;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float MoveSpeed;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float Accelerate;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float MoveAccelerate;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float FictionAccelerate;
	UPROPERTY(EditAnywhere,Category="Movement")
		float TurnSpeed;

public:
	void MoveForward(float Value);
	void TurnAround(float Value);
	void TurnLeft();
	void StopTurnLeft();
	void TurnRight();
	void StopTurnRight();
	void bOnTrottle();
	void bStopTrottle();

};
