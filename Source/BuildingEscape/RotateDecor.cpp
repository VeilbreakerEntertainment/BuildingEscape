// Copyright 2017 Veilbreaker Entertainment

#include "RotateDecor.h"

// Sets default values for this component's properties
URotateDecor::URotateDecor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void URotateDecor::BeginPlay()
{
	Super::BeginPlay();

	OnComponentActivated.AddDynamic(this, &URotateDecor::OnActivated);
}

//Called when activated by player
void URotateDecor::OnActivated(UActorComponent* component, bool bReset)
{
	Owner = GetOwner();

	if (Owner->ActorHasTag("Active"))
	{
		Owner->Tags.Remove(FName("Active"));
		Owner->AddActorWorldRotation(FRotator(-90, 0, 0), false, false);

		UE_LOG(LogTemp, Error, TEXT("Actor was deactivated."))
	}
	else
	{
		Owner->Tags.Add(FName("Active"));
		Owner->AddActorWorldRotation(FRotator(90, 0, 0), false, false);

		UE_LOG(LogTemp, Error, TEXT("Actor was activated."))
	}
}