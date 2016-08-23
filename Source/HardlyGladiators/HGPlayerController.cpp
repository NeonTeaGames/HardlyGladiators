// Copyright (C) 2016  Jens Pitkanen & Aleksi Talarmo

#include "HardlyGladiators.h"
#include "HGPlayerController.h"

void AHGPlayerController::SetupInputComponent() {
    Super::SetupInputComponent();
    InputComponent->BindAxis("Move Forward", this, &AHGPlayerController::MoveForward);
    InputComponent->BindAxis("Move Right", this, &AHGPlayerController::MoveRight);
    InputComponent->BindAxis("Look Up", this, &AHGPlayerController::LookUp);
    InputComponent->BindAxis("Look Right", this, &AHGPlayerController::LookRight);
}

void AHGPlayerController::MoveForward(float AxisValue) {
    FVector ForwardVector = this->GetActorForwardVector();
    ForwardVector.Z = 0;
    ForwardVector.Normalize();
    this->GetControlledPawn()->AddMovementInput(ForwardVector, AxisValue);
}

void AHGPlayerController::MoveRight(float AxisValue) {
    this->GetControlledPawn()->AddMovementInput(this->GetActorRightVector(), AxisValue);
}

void AHGPlayerController::LookUp(float AxisValue) {
    this->GetControlledPawn()->AddControllerPitchInput(AxisValue);
}

void AHGPlayerController::LookRight(float AxisValue) {
    this->GetControlledPawn()->AddControllerYawInput(AxisValue);
}
