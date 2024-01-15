// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyCharacter.h"

AMyGameModeBase::AMyGameModeBase() {
	static ConstructorHelpers::FClassFinder<AMyCharacter> BP_Character(TEXT("/Script/Engine.Blueprint'/Game/BP_MyCharacter.BP_MyCharacter_C'"));


	if (BP_Character.Succeeded()) {
		DefaultPawnClass = BP_Character.Class;
	}
}

