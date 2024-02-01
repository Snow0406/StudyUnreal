// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPlayer.h"

AMyGameModeBase::AMyGameModeBase() {
	static ConstructorHelpers::FClassFinder<AMyPlayer> BP_Player(TEXT("/Script/Engine.Blueprint'/Game/Blueprints/BP_MyPlayer.BP_MyPlayer_C'"));


	if (BP_Player.Succeeded()) {
		DefaultPawnClass = BP_Player.Class;
	}
}

