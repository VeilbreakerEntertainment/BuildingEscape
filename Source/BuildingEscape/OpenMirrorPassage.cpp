// Copyright 2017 Veilbreaker Entertainment

#include "OpenMirrorPassage.h"

// Sets default values for this component's properties
UOpenMirrorPassage::UOpenMirrorPassage()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UOpenMirrorPassage::BeginPlay()
{
	Super::BeginPlay();

	RootComponent = GetOwner()->GetRootComponent();
	WallCandleOne = RootComponent->GetChildComponent(0);
	WallCandleTwo = RootComponent->GetChildComponent(1);
	Mirror = RootComponent->GetChildComponent(2);
}

void UOpenMirrorPassage::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	/* if () // Somehow need to check if both candles are lit
	{
		Mirror->AddLocalOffset(LocalOffset);
		UE_LOG(LogTemp, Warning, TEXT("Both candles are now active!"))
	}
	*/
}