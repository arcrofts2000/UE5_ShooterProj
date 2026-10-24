// Copyright - Adam Crofts


#include "Components/VFCombatComponent.h"
#include "Engine.h"


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


void UVFCombatComponent::InitCycleWeapon()
{
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Red, TEXT("CYCLING WEAPON"));
}


void UVFCombatComponent::InitFireWeaponPressed()
{
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Red, TEXT("FIRING WEAPON"));
}


void UVFCombatComponent::InitFireWeaponReleased()
{
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Red, TEXT("NO LONGER FIRING WEAPON"));
}


void UVFCombatComponent::InitReloadWeapon()
{
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Red, TEXT("RELOADING WEAPON"));
}


void UVFCombatComponent::InitAimPressed()
{
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Red, TEXT("AIMING WEAPON"));
}


void UVFCombatComponent::InitAimReleased()
{
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Red, TEXT("NO LONGER AIMING WEAPON"));
}

