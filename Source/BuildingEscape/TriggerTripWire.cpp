// Copyright 2017 Veilbreaker Entertainment

#include "TriggerTripWire.h"


// Sets default values for this component's properties
UTriggerTripWire::UTriggerTripWire()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UTriggerTripWire::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	RootActor = GetOwner();

	RootActor->OnActorHit.AddDynamic(this, &UTriggerTripWire::OnHit);
}

void UTriggerTripWire::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	HitCharacter = Cast<ACharacter>(OtherActor);

	if (HitCharacter == Player)
	{
		// Close the doors
	}
}