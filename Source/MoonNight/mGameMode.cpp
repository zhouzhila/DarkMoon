// Fill out your copyright notice in the Description page of Project Settings.


#include "mGameMode.h"
#include "Role/mCharacter.h"
#include "Pawn/mPawn.h"

AmGameMode::AmGameMode()
{
	DefaultPawnClass = AmPawn::StaticClass();
}