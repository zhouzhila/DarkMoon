// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"
#include "mWheeledVehicle.generated.h"

/**
 * 
 */
UCLASS()
class MOONNIGHT_API AmWheeledVehicle : public AWheeledVehicle
{
	GENERATED_BODY()

		AmWheeledVehicle();

public:
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
public:
	void TestFunction();
	void TestFunciton1(float a);
};
