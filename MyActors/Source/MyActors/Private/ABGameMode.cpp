// Fill out your copyright notice in the Description page of Project Settings.

#include "ABGameMode.h"
#include "ABPawn.h"
#include "ABCharacter.h"
#include "ABPlayerController.h"
#include "ABPlayerState.h"
#include "ABGameState.h"

AABGameMode::AABGameMode() {
	DefaultPawnClass = AABCharacter::StaticClass();
	PlayerControllerClass = AABPlayerController::StaticClass();
	PlayerStateClass = AABPlayerState::StaticClass();
	GameStateClass = AABGameState::StaticClass();
}

void AABGameMode::PostLogin(APlayerController* NewPlayer) {
	ABLOG(Warning, TEXT("PostLogin Being"));
	Super::PostLogin(NewPlayer);

	auto ABPlayerState = Cast<AABPlayerState>(NewPlayer->PlayerState);
	ABCHECK(nullptr != ABPlayerState);
	ABPlayerState->InitPlayerData();
	ABLOG(Warning, TEXT("PostLogin End"));
}

void AABGameMode::PostInitializeComponents() {
	Super::PostInitializeComponents();
	ABGameState = Cast<AABGameState>(GameState);
}

void AABGameMode::AddScore(AABPlayerController* ScoredPlayer) {
	for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It) {
		const auto ABPlayerController = Cast<AABPlayerController>(It->Get());
		if ((nullptr != ABPlayerController) && (ScoredPlayer == ABPlayerController)) {
			ABPlayerController->AddGameScore();
			break;
		}
	}

	ABGameState->AddGameScore();
}