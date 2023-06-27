
#include "Turret.h"

#include "Tank.h"
#include "Kismet/GameplayStatics.h"


void ATurret::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if (InFireRange())
	{
		RotateTuret(Tank->GetActorLocation());
	}
}

void ATurret::BeginPlay()
{
	Super::BeginPlay();
	
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	
	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATurret::CheckFireCondition, FireRate, true);
	
}

void ATurret::CheckFireCondition()
{
	if (Tank == nullptr)
		return;
	
	if (InFireRange() && Tank->bAlive)
		Fire();
	
}

bool ATurret::InFireRange()
{
	
	float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
	if (Tank && (Distance <= DistanceRange))
	{
		return true;
	}
	return false;
}

void ATurret::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}


