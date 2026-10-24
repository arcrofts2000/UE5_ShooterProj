// Copyright - Adam Crofts

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VFCharacterBase.generated.h"

class UVFCombatComponent;
class USpringArmComponent;
class UCameraComponent;
class UInputAction;

UCLASS()
class UE5_SHOOTERPROJ_API AVFCharacterBase : public ACharacter
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;


public:	

	AVFCharacterBase();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:

	// Components

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UVFCombatComponent> CombatComp;

	// First Person arms
	UPROPERTY(VisibleAnywhere, Category = "Components")
	TObjectPtr<USkeletalMeshComponent> FPSMesh;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> CameraComp;


	// Weapon-based Input

	void Input_CycleWeapon();
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> CycleWeaponAction;

	void Input_FireWeaponPressed();
	void Input_FireWeaponReleased();
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> FireWeaponAction;

	void Input_ReloadWeapon();
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> ReloadWeaponAction;

	void Input_AimWeaponPressed();
	void Input_AimWeaponReleased();
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> AimWeaponAction;
};
