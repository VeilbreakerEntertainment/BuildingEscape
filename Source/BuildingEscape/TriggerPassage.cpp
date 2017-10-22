// Copyright 2017 Veilbreaker Entertainment

#include "TriggerPassage.h"
#include "OpenPassage.h"

// Sets default values for this component's properties
UTriggerPassage::UTriggerPassage()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UTriggerPassage::BeginPlay()
{
	Super::BeginPlay();

	TriggerComponent = GetOwner()->FindComponentByClass<UStaticMeshComponent>();

	TriggerComponent->SetNotifyRigidBodyCollision(true);
	TriggerComponent->OnComponentHit.AddDynamic(this, &UTriggerPassage::OnHit);
}

void UTriggerPassage::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (UOpenPassage* Passage = Hit.GetActor()->FindComponentByClass<UOpenPassage>())
	{
		Passage->ToggleActive();
	}
}