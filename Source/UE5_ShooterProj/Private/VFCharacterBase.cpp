// Copyright - Adam Crofts
#include "VFCharacterBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


AVFCharacterBase::AVFCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(GetRootComponent());
	SpringArmComp->TargetArmLength = 0.f;
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->bEnableCameraLag = true;
	SpringArmComp->CameraLagSpeed = 15.f;

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);
	CameraComp->bUsePawnControlRotation = false;

	FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>("FPSMesh");
	FPSMesh->SetupAttachment(CameraComp);
	FPSMesh->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::OnlyTickPoseWhenRendered;
	FPSMesh->PrimaryComponentTick.TickGroup = TG_PrePhysics;
	FPSMesh->bOnlyOwnerSee = true;
	FPSMesh->bOwnerNoSee = false;
	FPSMesh->bCastDynamicShadow = false;
	FPSMesh->bReceivesDecals = false;

	GetMesh()->bOwnerNoSee = true;
	GetMesh()->bOwnerNoSee = false;
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

