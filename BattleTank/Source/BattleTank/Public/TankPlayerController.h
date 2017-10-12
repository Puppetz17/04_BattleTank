// Copyright me

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "TankPlayerController.generated.h"

class UTankAimingComponent;

/**
 * Responsible for helping the player aim.
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimComRef);

private:
	void BeginPlay() override;

	void Tick(float) override;

	// Start the tank moving the barrel so that a shot would hit where 
	// the crosshair intersects the world
	void ATankPlayerController::AimTowardsCrosshair();

	// Return an OUT parameter, true if his landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;


	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.3333;

	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000;

	bool GetLookDirection(FVector2D screenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector, FVector&) const;
};
