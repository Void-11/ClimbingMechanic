// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CustomMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"

#pragma region ClimbTraces

TArray<FHitResult> UCustomMovementComponent::DoCapsuleTraceMultiByObject(const FVector& Start, const FVector& End, bool bShowDebugShape)
{
	TArray<FHitResult> OutCapsuletraceHitResults;
	UKismetSystemLibrary::CapsuleTraceMultiForObjects(
		this,
		Start,
		End,
		ClimbCapsuleTraceRadius,
		ClimbCapsuleTraceHalfHeight,
		ClimbableSurfaceTraceTypes,
		false,
		TArray<AActor*>(),
		bShowDebugShape ? EDrawDebugTrace::ForOneFrame : EDrawDebugTrace::None,
		OutCapsuletraceHitResults,
		false
	);

	return OutCapsuletraceHitResults;

}

#pragma endregion