// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MyActors.h"
#include "GameFramework/PlayerController.h"
#include "ABPlayerController.generated.h"


UCLASS()
class MYACTORS_API AABPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void PostInitializeComponents() override;
	virtual void OnPossess(APawn* aPawn) override;
};
