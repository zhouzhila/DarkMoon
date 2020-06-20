// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "mCharacter.generated.h"

UCLASS()
class MOONNIGHT_API AmCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AmCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	void Trottle();
	void ReleaseTrottle();
	void Break();
	void ReleaseBreak();
	void HandBreak();
	void ReleaseHandBreak();

	void MoveForward(float Value);
	void MoveLeft(float Value);

	UPROPERTY(EditAnywhere)
		class UMovementComponent* mMovementComp;

public:
	bool onTrottle = false;
	bool onBreak = false;
	bool onHandBreak = false;

public:
	UPROPERTY(EditAnywhere, Category = "RoleMovement")
		float mAccelerate;
	UPROPERTY(EditAnywhere, Category = "RoleMovement")
		float mMaxSpeed;
	UPROPERTY(EditAnywhere, Category = "RoleMovement")
		float mVelocity;

	float NewSpeed;
	float Fiction;

};
