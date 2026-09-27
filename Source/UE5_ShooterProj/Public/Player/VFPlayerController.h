// Copyright - Adam Crofts

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "VFPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class UE5_SHOOTERPROJ_API AVFPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;


public:

	AVFPlayerController();


private:

	UPROPERTY(EditAnywhere, Category = "VF|Input")
	TObjectPtr<UInputMappingContext> DefaultIMC;

	UPROPERTY(EditAnywhere, Category = "VF|Input")
	TObjectPtr<UInputAction> ActionLook;
	void Input_Look(const FInputActionValue& InputActionValue);

	UPROPERTY(EditAnywhere, Category = "VF|Input")
	TObjectPtr<UInputAction> ActionMove;
	void Input_Move(const FInputActionValue& InputActionValue);

	UPROPERTY(EditAnywhere, Category = "VF|Input")
	TObjectPtr<UInputAction> ActionJump;
	void Input_Jump();

	UPROPERTY(EditAnywhere, Category = "VF|Input")
	TObjectPtr<UInputAction> ActionCrouch;
	void Input_Crouch();

};
