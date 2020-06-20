// Fill out your copyright notice in the Description page of Project Settings.


#include "mWheeledVehicle.h"
#include "Components/InputComponent.h"


AmWheeledVehicle::AmWheeledVehicle()
{

}

void AmWheeledVehicle::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	//Super::SetupPlayerInputComponent(PlayerInputComponent);

	//PlayerInputComponent->BindAxis("", this, &AmWheeledVehicle::TestFunction);
	
	PlayerInputComponent->BindAction("", IE_Pressed, this, &AmWheeledVehicle::TestFunction);

	PlayerInputComponent->BindAxis("", this, &AmWheeledVehicle::TestFunciton1);

}

void AmWheeledVehicle::TestFunction()
{
	
}

void AmWheeledVehicle::TestFunciton1(float Val)
{
	//GetVehicleMovementComponent()->SetThrottleInput(Val);
}
