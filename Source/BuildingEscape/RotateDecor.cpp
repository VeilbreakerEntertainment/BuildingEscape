// Copyright 2017 Veilbreaker Entertainment

#include "RotateDecor.h"


// Sets default values for this component's properties
URotateDecor::URotateDecor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URotateDecor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URotateDecor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

