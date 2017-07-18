// Copyright 2017 Veilbreaker Entertainment

#pragma once

#include "Engine/TriggerVolume.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	//UPROPERTY is Unreal engine specific, read documentation.
	UPROPERTY(EditAnywhere)
		float OpenAngle = 90.f;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 1.f;

	UPROPERTY(EditAnywhere)
		float TriggerMass = 0.f;

	float LastDoorOpenTime;
	float GetTotalMassOfActorsOnPlate(); //Returns total mass in kg

	AActor* ActorThatOpens; //APawn would also be usable in this case (it inherits from Actor)
	AActor* Owner;
};
