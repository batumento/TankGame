// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AToonGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	void ActorDied(AActor* DeadActor);

protected:

	virtual  void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void StartGameWidget();

	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool bWonGame);
	
private:

	class ATank* TankRef;
	class ATankPlayerController* TankController;

	float StartGame = 4.f;

	void HandleGameStart();

	int32 TargetTowers;
	int32 GetTargetTowerCount();
};
