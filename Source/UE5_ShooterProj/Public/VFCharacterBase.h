// Copyright - Adam Crofts

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VFCharacterBase.generated.h"

class USpringArmComponent;
class UCameraComponent;

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

	// First Person arms
	UPROPERTY(VisibleAnywhere, Category = "Components")
	TObjectPtr<USkeletalMeshComponent> FPSMesh;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> CameraComp;
};
