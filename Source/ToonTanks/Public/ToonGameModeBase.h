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
	
private:

	class ATank* TankRef;
	class ATankPlayerController* TankController;

	float StartGame = 3.f;

	void HandleGameStart();
};
