// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */

UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	
	ATank();
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void HandleDestruction();

	APlayerController* GetTankPlayerController() const { return TankPlayerController; }
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(VisibleAnywhere, Category="Components", meta=(AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArmComponent;
	UPROPERTY(VisibleAnywhere, Category="Components", meta=(AllowPrivateAccess = "true"))
	UCameraComponent* CameraComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Movement/Rotation", meta=(AllowPrivateAccess = "true"))
	float Speed = 5;
	UPROPERTY(EditAnywhere, Category= "Movement/Rotation",meta=(AllowPrivateAccess = "true"))
	float RotationSpeed = 5;
	UPROPERTY(EditAnywhere, Category="Movement/Rotation",meta=(AllowPrivateAccess = "true"))
	int InterpSpeed = 15;
	
	
	FVector MovementDirection;
	UPROPERTY(EditAnywhere, Category="Movement")
	float MovementSpeed = 500;
	
	void MoveForward(float value);
	void MoveRight(float value);

	
	UPROPERTY()
	APlayerController* TankPlayerController;
	
};
