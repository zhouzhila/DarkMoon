// Fill out your copyright notice in the Description page of Project Settings.


#include "mCharacter.h"
#include "Components/InputComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Controller.h"
#include "UnrealMathUtility.h"
#include "Engine/Engine.h"
#include "GameFramework/MovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AmCharacter::AmCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Initial Role Movement Index
	mAccelerate = 0.f;
	mMaxSpeed = 1600.f;

	GetCharacterMovement()->MaxAcceleration = 200.f;
	GetCharacterMovement()->MaxWalkSpeed = mMaxSpeed;
	
	NewSpeed = 0.f;
	Fiction = 0.f;
}

// Called when the game starts or when spawned
void AmCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AmCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



	if (onTrottle) {


		MoveForward(FMath::Min(mAccelerate+=DeltaTime,1.f));
		mAccelerate = FMath::Min(mAccelerate += DeltaTime, 1.f);

		NewSpeed += mAccelerate * GetCharacterMovement()->MaxAcceleration;

		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue,FString::FromInt(GetCharacterMovement()->GetLastUpdateVelocity().X),true );
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::FromInt(mAccelerate*10), true);
		
	}
	else if(mAccelerate>0)
	{
		
		Fiction = NewSpeed / mMaxSpeed;
		NewSpeed -= GetCharacterMovement()->MaxAcceleration;
		if (Fiction >0) MoveForward(FMath::Max(mAccelerate -= DeltaTime / Fiction, 0.f));
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::FromInt(GetCharacterMovement()->GetLastUpdateVelocity().X), true);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::FromInt(mAccelerate * 10), true);
	}
	
	
}

// Called to bind functionality to input
void AmCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Trottle", IE_Pressed, this, &AmCharacter::Trottle);
	PlayerInputComponent->BindAction("Trottle", IE_Released, this, &AmCharacter::ReleaseTrottle);

	PlayerInputComponent->BindAction("Break", IE_Pressed, this, &AmCharacter::Break);
	PlayerInputComponent->BindAction("Break", IE_Released, this, &AmCharacter::ReleaseBreak);

	PlayerInputComponent->BindAction("Break", IE_Pressed, this, &AmCharacter::HandBreak);
	PlayerInputComponent->BindAction("Break", IE_Released, this, &AmCharacter::ReleaseHandBreak);


	PlayerInputComponent->BindAxis("MoveLeft", this, &AmCharacter::MoveLeft);
}

void AmCharacter::Trottle()
{
	onTrottle = true;
}

void AmCharacter::ReleaseTrottle()
{
	onTrottle = false;
}

void AmCharacter::Break()
{
	onBreak = true;
}

void AmCharacter::ReleaseBreak()
{
	onBreak = false;
}

void AmCharacter::HandBreak()
{
	onHandBreak = true;
}

void AmCharacter::ReleaseHandBreak()
{
	onHandBreak = false;
}

void AmCharacter::MoveForward(float Value)
{
	FVector	Direction;
	Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);

	AddMovementInput(Direction, Value);
}

void AmCharacter::MoveLeft(float Value)
{

	if (onTrottle || onBreak && !onHandBreak)
	{
		AddControllerYawInput(Value);
	}
	else
	{

	}
}

