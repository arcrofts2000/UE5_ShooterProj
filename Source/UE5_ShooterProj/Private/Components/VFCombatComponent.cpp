// Copyright - Adam Crofts


#include "Components/VFCombatComponent.h"


UVFCombatComponent::UVFCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;


}


void UVFCombatComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


void UVFCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

