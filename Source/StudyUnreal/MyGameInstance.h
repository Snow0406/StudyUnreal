// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
USTRUCT()
struct  FMyCharacterData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxHp;

};

UCLASS()
class STUDYUNREAL_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	class UDataTable* CharacterDataTable;
public:
	UMyGameInstance();
public:
	virtual void Init() override;
public:
	FMyCharacterData* GetCharacterData(int32 Level);
};
