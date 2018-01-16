// Copyright 2017 Veilbreaker Entertainment

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "OpenMirrorPassage.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenMirrorPassage : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenMirrorPassage();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
