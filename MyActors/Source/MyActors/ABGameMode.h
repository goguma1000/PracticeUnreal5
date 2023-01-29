// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MyActors.h"
#include "GameFramework/GameModeBase.h"
#include "ABGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MYACTORS_API AABGameMode : public AGameModeBase
{
	GENERATED_BODY()

	AABGameMode();

public:
	virtual void PostLogin(APlayerController* NewPlayer) override;
};
