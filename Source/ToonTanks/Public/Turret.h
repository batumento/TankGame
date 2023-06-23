// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Turret.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class TOONTANKS_API ATurret : public ABasePawn
{
	GENERATED_BODY()


public:
	virtual void Tick(float DeltaSeconds) override;

	void HandleDestruction();
	
protected:
	virtual void BeginPlay() override;

private:
	
	ATank* Tank;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Range", meta=(AllowPrivateAccess = "true"))
	float DistanceRange = 100;

	FTimerHandle FireRateTimerHandle;
	float FireRate = 2.f;
	void CheckFireCondition();
	
	bool InFireRange();
};
