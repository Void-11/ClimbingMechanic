// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/CharacterAnimInstance.h"
#include "ClimbingMechanic/ClimbingMechanicCharacter.h"
#include "Components/CustomMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	ClimbingMechanicCharacter = Cast<AClimbingMechanicCharacter>(TryGetPawnOwner());

	if (ClimbingMechanicCharacter)
	{
		CustomMovementComponent = ClimbingMechanicCharacter->GetCustomMovementComponent();
	}
}

void UCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!ClimbingMechanicCharacter || !CustomMovementComponent) return;

	GetLandSpeed();
	GetAirSpeed();
	GetShouldMove();
	GetIsFalling();
	GetIsClimbing();
}

void UCharacterAnimInstance::GetLandSpeed()
{
	LandSpeed = UKismetMathLibrary::VSizeXY(ClimbingMechanicCharacter->GetVelocity());
	
}

void UCharacterAnimInstance::GetAirSpeed()
{
	AirSpeed = ClimbingMechanicCharacter->GetVelocity().Z;
}

void UCharacterAnimInstance::GetShouldMove()
{
	bShouldMove =
	CustomMovementComponent->GetCurrentAcceleration().Size() > 0 &&
	LandSpeed > 5.f &&
	!bIsFalling;
}

void UCharacterAnimInstance::GetIsFalling()
{
	bIsFalling = CustomMovementComponent->IsFalling();
}

void UCharacterAnimInstance::GetIsClimbing()
{
	bIsClimbing = CustomMovementComponent->IsClimbing();
}