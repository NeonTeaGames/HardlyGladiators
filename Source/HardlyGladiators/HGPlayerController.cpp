// Copyright (C) 2016  Jens Pitkanen & Aleksi Talarmo

#include "HardlyGladiators.h"
#include "HGPlayerController.h"

void AHGPlayerController::BeginPlay() {
    this->Character = Cast<AHGCharacter>(this->GetControlledPawn());
}

void AHGPlayerController::SetupInputComponent() {
    Super::SetupInputComponent();
    InputComponent->BindAxis("Move Forward", this, &AHGPlayerController::MoveForward);
    InputComponent->BindAxis("Move Right", this, &AHGPlayerController::MoveRight);
    InputComponent->BindAxis("Look Up", this, &AHGPlayerController::LookUp);
    InputComponent->BindAxis("Look Right", this, &AHGPlayerController::LookRight);
    InputComponent->BindAction("Action (Right Hand)", IE_Pressed, this, &AHGPlayerController::ActionRightHand);
    InputComponent->BindAction("Action (Left Hand)", IE_Pressed, this, &AHGPlayerController::ActionLeftHand);
}

void AHGPlayerController::MoveForward(float AxisValue) {
    FVector ForwardVector = this->GetActorForwardVector();
    ForwardVector.Z = 0;
    ForwardVector.Normalize();
    this->Character->AddMovementInput(ForwardVector, AxisValue);
}

void AHGPlayerController::MoveRight(float AxisValue) {
    this->Character->AddMovementInput(this->GetActorRightVector(), AxisValue);
}

void AHGPlayerController::LookUp(float AxisValue) {
    this->Character->AddControllerPitchInput(AxisValue);
}

void AHGPlayerController::LookRight(float AxisValue) {
    this->Character->AddControllerYawInput(AxisValue);
}

void AHGPlayerController::ActionRightHand() {
    this->Character->OnAction(false);
}

void AHGPlayerController::ActionLeftHand() {
    this->Character->OnAction(true);
}
