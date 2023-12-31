// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class UProjectileMovementComponent;
class UParticleSystem;
class USoundBase;
class UCameraShakeBase;


UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Combat", meta=(AllowPrivateAccess = "true"))
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(VisibleAnywhere)
	UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY()
	float Damage = 50.f;
	
	UFUNCTION()
	void OnHit(
		UPrimitiveComponent* HitComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		FVector NormalImpulse,
		const FHitResult& Hit);
	
	UPROPERTY(EditAnywhere, Category="Combat")
	UParticleSystem* HitParticles;

	UPROPERTY(EditAnywhere,Category="Combat")
	UParticleSystemComponent* TrailParticles;

	UPROPERTY(EditAnywhere,Category="Combat")
	USoundBase* LaunchSound;
	UPROPERTY(EditAnywhere,Category="Combat")
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category="Combat")
	TSubclassOf<UCameraShakeBase> HitCameraShakeClass;
};
