// Copyright 2017 Veilbreaker Entertainment

#include "TeleportStone.h"
#include "TriggerStone.h"

// Sets default values for this component's properties
UTriggerStone::UTriggerStone()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

// Called when the game starts
void UTriggerStone::BeginPlay()
{
	Super::BeginPlay();

	TriggerComponent = GetOwner()->FindComponentByClass<UStaticMeshComponent>();

	TriggerComponent->SetNotifyRigidBodyCollision(true);
	TriggerComponent->OnComponentHit.AddDynamic(this, &UTriggerStone::OnHit);
}

void UTriggerStone::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (UTeleportStone* Stone = Hit.GetActor()->FindComponentByClass<UTeleportStone>())
	{
		Stone->ToggleActive();
		UE_LOG(LogTemp, Warning, TEXT("Stone has been activated."))
	}
}