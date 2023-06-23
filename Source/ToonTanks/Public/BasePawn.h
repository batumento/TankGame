// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"


class UCapsuleComponent;

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	void HandleDestruction();
	
protected:
	
	void RotateTuret(FVector LookAtTarget);
	void Fire();
	
	FORCEINLINE
	UStaticMeshComponent* GetBaseMesh(){ return BaseMesh; }
	FORCEINLINE
	USceneComponent* GetProjectile(){ return BaseMesh; }
	
	UPROPERTY(EditDefaultsOnly, Category= "Combat")
	TSubclassOf<class AProjectile> ProjectileClass;
private:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Components", meta=(AllowPrivateAccess = "true"))
	UCapsuleComponent* CapsuleComponent;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess= "true"))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess= "true"))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess= "true"))  
	USceneComponent* ProjectileSpawnPoint;
	
};
