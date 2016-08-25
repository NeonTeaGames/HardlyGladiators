// Copyright (C) 2016  Jens Pitkanen & Aleksi Talarmo

#include "HardlyGladiators.h"
#include "HGCharacter.h"

AHGCharacter::AHGCharacter() {
	PrimaryActorTick.bCanEverTick = true;
}

void AHGCharacter::BeginPlay() {
	Super::BeginPlay();	
}

void AHGCharacter::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
}
