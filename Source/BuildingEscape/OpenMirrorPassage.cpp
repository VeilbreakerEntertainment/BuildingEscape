// Copyright 2017 Veilbreaker Entertainment

#include "OpenMirrorPassage.h"

// Sets default values for this component's properties
UOpenMirrorPassage::UOpenMirrorPassage()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
	PrimaryComponentTick.bAllowTickOnDedicatedServer = true;
}

// Called when the game starts
void UOpenMirrorPassage::BeginPlay()
{
	Super::BeginPlay();

	RootComponent = GetOwner()->GetRootComponent();
	WallCandleOneAsChild = Cast<UChildActorComponent>(RootComponent->GetChildComponent(0));
	WallCandleTwoAsChild = Cast<UChildActorComponent>(RootComponent->GetChildComponent(1));
	WallCandleOne = WallCandleOneAsChild->GetChildActor();
	WallCandleTwo = WallCandleTwoAsChild->GetChildActor();
	Mirror = RootComponent->GetChildComponent(2);
}

void UOpenMirrorPassage::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (WallCandleOne->ActorHasTag(FName("Lit")) && WallCandleTwo->ActorHasTag(FName("Lit")))
	{
		if (!GetOwner()->ActorHasTag(FName("PassageOpen")))
		{
			Mirror->AddLocalOffset(LocalOffset);
			GetOwner()->Tags.Add(FName("PassageOpen"));
		}
	}
}