// Copyright - Adam Crofts

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VFCombatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE5_SHOOTERPROJ_API UVFCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UVFCombatComponent();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
