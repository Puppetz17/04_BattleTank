// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include <Engine/World.h>
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) 
	UE_LOG(LogTemp, Warning, TEXT("can't find player tank"))
	else
		UE_LOG(LogTemp,Warning,TEXT("AIController found player %s"), *PlayerTank->GetName())
		

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Aim at player
	if (GetControlledTank())
	{	// TODO Move towards the player

		// Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire if ready
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);

	
	}


