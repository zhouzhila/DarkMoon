// Fill out your copyright notice in the Description page of Project Settings.


#include "mPawn.h"
#include "Components/InputComponent.h"
#include "Components/SphereComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Controller.h"
#include "Public\Math\UnrealMathUtility.h"
#include "Engine.h"
#include "Engine/StaticMesh.h"
#include "Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"

// Sets default values
AmPawn::AmPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mSphere = CreateDefaultSubobject<USphereComponent>(TEXT("mSphere"));
	mSphere->SetupAttachment(RootComponent);

	mSphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mSphereMesh"));
	mSphereMesh->SetupAttachment(mSphere);

	mCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("mCamera"));
	mCamera->SetupAttachment(mSphere);
	mCamera->SetRelativeLocation(FVector(-250.f, 0.f, 250.f));
	mCamera->SetRelativeRotation(FRotator(-15.f, 0.f, 0.f));

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	MaxSpeed = 12.0f;
	Accelerate = 8.0f;
	FictionAccelerate = 2.f;
	TurnSpeed = 0.4f;

	//Test Mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> TestMesh (TEXT("StaticMesh'/Game/Mesh/TestMesh.TestMesh'"));

	if (TestMesh.Succeeded())
	{
		mSphereMesh->SetStaticMesh(TestMesh.Object);
		
	}
}

// Called when the game starts or when spawned
void AmPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AmPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bTrottle) {

		MoveAccelerate += DeltaTime;
		MoveAccelerate = FMath::Min(MoveAccelerate, Accelerate);
		MoveSpeed += MoveAccelerate * DeltaTime;
		MoveSpeed = FMath::Min(MaxSpeed, MoveSpeed);
		MoveForward(MoveSpeed);

		if (bTurnLeft)
		{
			TurnAround(TurnSpeed);
		}
		else if (bTurnRight)
		{
			TurnAround(-TurnSpeed);
		}
	}
	else if (!bTrottle && MoveSpeed > 0) {
		
		MoveAccelerate = 0.f;
		MoveSpeed -= FictionAccelerate * DeltaTime;
		MoveForward(MoveSpeed);

		if (bTurnLeft)
		{
			TurnAround(TurnSpeed);
		}
		else if (bTurnRight)
		{
			TurnAround(-TurnSpeed);
		}
	}
	else
	{
		MoveAccelerate = 0.f;
	}

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(MoveAccelerate *100), true);





}

// Called to bind functionality to input
void AmPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Trottle", IE_Pressed, this, &AmPawn::bOnTrottle);
	PlayerInputComponent->BindAction("Trottle", IE_Released, this, &AmPawn::bStopTrottle);

	PlayerInputComponent->BindAction("TurnLeft", IE_Pressed, this, &AmPawn::TurnLeft);
	PlayerInputComponent->BindAction("TurnLeft", IE_Released, this, &AmPawn::StopTurnLeft);
	PlayerInputComponent->BindAction("TurnRight", IE_Pressed, this, &AmPawn::TurnRight);
	PlayerInputComponent->BindAction("TurnRight", IE_Released, this, &AmPawn::StopTurnRight);
	

}

void AmPawn::MoveForward(float Value)
{
	FRotator mRotator;
	mRotator = mSphere->GetComponentRotation();
	FVector Direction;
	Direction = mSphere->GetComponentLocation();
	Direction += FVector(Value * FMath::Cos(FMath::DegreesToRadians(mRotator.Yaw)), Value * FMath::Sin(FMath::DegreesToRadians(mRotator.Yaw)), 0.f);
	///写到这了，用三角函数算一下x、y的偏移即可

	mSphere->SetRelativeLocation(Direction);
}

void AmPawn::TurnAround(float Value)
{
		
		FRotator mRotator;
		mRotator = mSphere->GetComponentRotation();
		mRotator += FRotator(0.f, -Value, 0.f);

		mSphere->SetRelativeRotation(mRotator);

}

void AmPawn::TurnLeft()
{
	bTurnLeft = true;
}

void AmPawn::StopTurnLeft()
{
	bTurnLeft = false;
}

void AmPawn::TurnRight()
{
	bTurnRight = true;
}

void AmPawn::StopTurnRight()
{
	bTurnRight = false;
}

void AmPawn::bOnTrottle()
{
	bTrottle = true;
	
	FString TestValue;

}

void AmPawn::bStopTrottle()
{
	bTrottle = false;

	FString TestValue;

}

