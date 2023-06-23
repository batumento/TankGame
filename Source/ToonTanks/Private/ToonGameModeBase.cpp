// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonGameModeBase.h"

#include "Tank.h"
#include "Turret.h"
#include "Kismet/GameplayStatics.h"

void AToonGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	TankRef = Cast<ATank>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
}

void AToonGameModeBase::ActorDied(AActor* DeadActor)
{
	if (TankRef == DeadActor)
	{
		TankRef->HandleDestruction();
		if (TankRef->GetTankPlayerController())
		{
			TankRef->DisableInput(TankRef->GetTankPlayerController());
		}
	}
	else if (ATurret* DestroyedTurret = Cast<ATurret>(DeadActor))
	{
		DestroyedTurret->HandleDestruction();
	}
	
}
