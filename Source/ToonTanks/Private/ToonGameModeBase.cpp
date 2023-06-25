// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonGameModeBase.h"

#include "Tank.h"
#include "TankPlayerController.h"
#include "Turret.h"
#include "Kismet/GameplayStatics.h"

void AToonGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	HandleGameStart();
}

void AToonGameModeBase::ActorDied(AActor* DeadActor)
{
	if (TankRef == DeadActor)
	{
		TankRef->HandleDestruction();
		if (TankController)
		{
			TankController->SetPlayerEnabledState(false);
		}
	}
	else if (ATurret* DestroyedTurret = Cast<ATurret>(DeadActor))
	{
		DestroyedTurret->HandleDestruction();
	}
	
}

void AToonGameModeBase::HandleGameStart()
{
	TankRef = Cast<ATank>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	TankController = Cast<ATankPlayerController>(UGameplayStatics::GetPlayerController(this,0));

	if (TankController)
	{
		TankController->SetPlayerEnabledState(false);

		FTimerHandle PlayerEnableTimerHandle;
		FTimerDelegate PlayerEnableTimerDelegate = FTimerDelegate::CreateUObject(
			TankController,
			&ATankPlayerController::SetPlayerEnabledState,
			true
			);

		GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle,
			PlayerEnableTimerDelegate,
			StartGame,
			false);
	}
}

