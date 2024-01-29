// Copyright Epic Games, Inc. All Rights Reserved.

#include "ClimbingMechanicGameMode.h"
#include "ClimbingMechanicCharacter.h"
#include "UObject/ConstructorHelpers.h"

AClimbingMechanicGameMode::AClimbingMechanicGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
