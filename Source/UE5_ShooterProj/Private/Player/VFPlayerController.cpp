// Copyright - Adam Crofts


#include "Player/VFPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

AVFPlayerController::AVFPlayerController()
{
	bReplicates = true;
}



void AVFPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (IsValid(Subsystem))
		Subsystem->AddMappingContext(DefaultIMC, 0);
}



void AVFPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* DefaultInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	DefaultInputComponent->BindAction(ActionLook, ETriggerEvent::Triggered, this, &AVFPlayerController::Input_Look);
	DefaultInputComponent->BindAction(ActionMove, ETriggerEvent::Triggered, this, &AVFPlayerController::Input_Move);
	DefaultInputComponent->BindAction(ActionJump, ETriggerEvent::Started, this, &AVFPlayerController::Input_Jump);
	DefaultInputComponent->BindAction(ActionCrouch, ETriggerEvent::Started, this, &AVFPlayerController::Input_Crouch);
}



void AVFPlayerController::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookValue = InputActionValue.Get<FVector2D>();

	AddYawInput(LookValue.X);
	AddPitchInput(LookValue.Y);
}



void AVFPlayerController::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MoveValue = InputActionValue.Get<FVector2D>();

	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, MoveValue.Y);
		ControlledPawn->AddMovementInput(RightDirection, MoveValue.X);
	}
}



void AVFPlayerController::Input_Jump()
{
	if (!IsValid(GetCharacter())) 
		return;

	if (UCharacterMovementComponent* CMC = GetCharacter()->GetCharacterMovement())
	{
		if (CMC->bWantsToCrouch)
			CMC->bWantsToCrouch = false;
		else
			GetCharacter()->Jump();
	}
}



void AVFPlayerController::Input_Crouch()
{
	if (!IsValid(GetCharacter()))
		return;

	if (UCharacterMovementComponent* CMC = GetCharacter()->GetCharacterMovement(); IsValid(CMC))
	{
		CMC->bWantsToCrouch = !CMC->bWantsToCrouch;
	}
}