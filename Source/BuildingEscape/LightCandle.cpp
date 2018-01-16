// Copyright 2017 Veilbreaker Entertainment

#include "LightCandle.h"


// Sets default values for this component's properties
ULightCandle::ULightCandle()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void ULightCandle::BeginPlay()
{
	Super::BeginPlay();

	OnComponentActivated.AddDynamic(this, &ULightCandle::OnActivated);
}

void ULightCandle::OnActivated(UActorComponent* Component, bool bReset)
{
	RootComponent = GetOwner()->GetRootComponent();

	// Action for actor to perform upon activation.
}