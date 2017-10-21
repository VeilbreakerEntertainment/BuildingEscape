// Copyright 2017 Veilbreaker Entertainment

#include "OpenPassage.h"

// Sets default values for this component's properties
UOpenPassage::UOpenPassage()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UOpenPassage::BeginPlay()
{
	Super::BeginPlay();

	OnComponentActivated.AddDynamic(this, &UOpenPassage::OnActivated);
}

// Called every frame
void UOpenPassage::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UOpenPassage::OnActivated(UActorComponent* Component, bool bReset)
{
	UE_LOG(LogTemp, Warning, TEXT("OpenPassge.cpp: Passage activated"))
}