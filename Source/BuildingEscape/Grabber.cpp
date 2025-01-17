// Copyright 2017 Veilbreaker Entertainment

#include "Grabber.h"
#include "RotateDecor.h"
#include "Engine/World.h"
#include "Gameframework/PlayerController.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	FindPhysicsHandleComponent();
	SetupInputComponent();
}

void UGrabber::FindPhysicsHandleComponent()
{
	//Look for attached Physics Handle
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	if (PhysicsHandle == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("% missing physics handle component!"), *GetOwner()->GetName())
	}
}

void UGrabber::SetupInputComponent()
{
	//Look for attached Input Component
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	if (InputComponent)
	{
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
		InputComponent->BindAction("Activate", IE_Pressed, this, &UGrabber::ActivateTarget);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("% missing Input Component!"), *GetOwner()->GetName())
	}
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!PhysicsHandle) { return; }

	//If physics handle is attached
	if (PhysicsHandle->GrabbedComponent)
	{
		//Move the object that we're holding
		PhysicsHandle->SetTargetLocation(GetReachLineEnd());
	}
}

//Grab action key has been pressed
void UGrabber::Grab()
{
	//Ray-cast reach any actors with physics body collision channel set
	FHitResult HitResult = GetFirstPhysicsBodyInReach();
	UPrimitiveComponent* ComponentToGrab = HitResult.GetComponent();
	AActor* ActorHit = HitResult.GetActor();

	//If something was hit then attach a physics handle
	if (ActorHit && !(ActorHit->FindComponentByClass<URotateDecor>()))
	{
		//Attach physics handle
		if (!PhysicsHandle) { return; }

		PhysicsHandle->GrabComponentAtLocationWithRotation(
			ComponentToGrab,
			NAME_None, //No bones needed
			ComponentToGrab->GetOwner()->GetActorLocation(),
			ComponentToGrab->GetOwner()->GetActorRotation()
		);
	}
}

//Grab action key has been released
void UGrabber::Release()
{
	if (!PhysicsHandle) { return; }

	PhysicsHandle->ReleaseComponent();
}

//Activate action key has been pressed
void UGrabber::ActivateTarget()
{
	//Ray-cast reach any actors with physics body collision channel set
	FHitResult HitResult = GetFirstPhysicsBodyInReach();
	UPrimitiveComponent* ComponentToActivate = HitResult.GetComponent();
	AActor* ActorHit = HitResult.GetActor();

	//If something was hit then attempt to activate it
	if (ActorHit)
	{
		//Check if actor can be activated
		if (ActorHit->ActorHasTag("Activatable"))
		{
			if (URotateDecor* RotateDecor = ActorHit->FindComponentByClass<URotateDecor>())
			{
				RotateDecor->ToggleActive();
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Actor hit was not able to be activated."))
		}
	}
}

const FHitResult UGrabber::GetFirstPhysicsBodyInReach()
{
	FHitResult HitResult;
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	GetWorld()->LineTraceSingleByObjectType(
		OUT HitResult,
		GetReachLineStart(),
		GetReachLineEnd(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);

	return HitResult;
}

FVector UGrabber::GetReachLineStart()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	return PlayerViewPointLocation;
}

FVector UGrabber::GetReachLineEnd()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	return PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
}