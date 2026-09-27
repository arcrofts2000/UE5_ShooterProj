// Copyright - Adam Crofts
#include "Character/VFCharacterBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


AVFCharacterBase::AVFCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	// Spring Arm used to add a bit of drag to the player, making the movement feel smoother rather than snappy
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(GetRootComponent());
	SpringArmComp->TargetArmLength = 0.f;
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->bEnableCameraLag = true;
	SpringArmComp->CameraLagSpeed = 15.f;

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);
	CameraComp->bUsePawnControlRotation = false;

	// Basic defaults for First Person Mesh - Dynamic shadow is unnecessary, as it would look odd for the player to see floating arms
	FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>("FPSMesh");
	FPSMesh->SetupAttachment(CameraComp);
	FPSMesh->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::OnlyTickPoseWhenRendered;
	FPSMesh->PrimaryComponentTick.TickGroup = TG_PrePhysics;
	FPSMesh->bOnlyOwnerSee = true;
	FPSMesh->bOwnerNoSee = false;
	FPSMesh->bCastDynamicShadow = false;
	FPSMesh->bReceivesDecals = false;

	// Set the mesh (Third Person Mesh) to prevent owner from seeing this, and allowing others to see it
	// Receives decals is turned off to increase performance
	GetMesh()->bOnlyOwnerSee = false;
	GetMesh()->bOwnerNoSee = true;
	GetMesh()->bReceivesDecals = false;
}

void AVFCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AVFCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVFCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

