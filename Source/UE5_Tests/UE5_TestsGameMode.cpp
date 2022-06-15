// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5_TestsGameMode.h"
#include "UE5_TestsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE5_TestsGameMode::AUE5_TestsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
