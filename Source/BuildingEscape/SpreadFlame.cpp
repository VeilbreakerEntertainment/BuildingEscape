// Copyright 2017 Veilbreaker Entertainment

#include "SpreadFlame.h"
#include "LightCandle.h"

// Sets default values for this component's properties
USpreadFlame::USpreadFlame()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

// Called when the game starts
void USpreadFlame::BeginPlay()
{
	Super::BeginPlay();

	TriggerComponent = GetOwner()->FindComponentByClass<UStaticMeshComponent>();

	TriggerComponent->SetNotifyRigidBodyCollision(true);
	TriggerComponent->OnComponentHit.AddDynamic(this, &USpreadFlame::OnHit);
}

void USpreadFlame::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (ULightCandle* Flame = Hit.GetActor()->FindComponentByClass<ULightCandle>())
	{
		Flame->ToggleActive();
	}
}