// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"

ATank::ATank()
{
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("Spring Arm Component");
	SpringArmComponent->SetupAttachment(RootComponent);
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera Component");
	CameraComponent->SetupAttachment(SpringArmComponent);
}



void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Turn"),this, &ATank::MoveRight);

	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ATank::Fire);
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	
	TankPlayerController = Cast<APlayerController>(GetController());
}


void ATank::Tick(float DeltaTime)
{
	
	if (TankPlayerController)
	{
		if (!MovementDirection.IsZero())
		{
			AddMovementInput(MovementDirection);
			GetBaseMesh()->SetRelativeRotation(UKismetMathLibrary::RInterpTo(
				GetBaseMesh()->GetRelativeRotation(),
				UKismetMathLibrary::MakeRotFromX(GetVelocity()),
				DeltaTime,
				InterpSpeed));
		}
		FHitResult HitResult;
		TankPlayerController->GetHitResultUnderCursor(
			ECC_Visibility,
			false,
			HitResult);

		RotateTuret(HitResult.ImpactPoint);
	}
	
}

void ATank::MoveRight(float value)
{
	MovementDirection.Y = FMath::Clamp(value,-1,1);
}

void ATank::MoveForward(float value)
{
	MovementDirection.X = FMath::Clamp(value,-1,1);
	
}

void ATank::HandleDestruction()
{
	Super::HandleDestruction();
	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
	bAlive = false;
}



