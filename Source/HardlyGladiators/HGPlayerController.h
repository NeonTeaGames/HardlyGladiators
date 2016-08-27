// Copyright (C) 2016  Jens Pitkanen & Aleksi Talarmo

#pragma once

#include "GameFramework/PlayerController.h"
#include "HGCharacter.h"
#include "HGPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class HARDLYGLADIATORS_API AHGPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
    AHGCharacter *Character;

    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;

    void MoveForward(float AxisValue);
    void MoveRight(float AxisValue);
    void LookUp(float AxisValue);
    void LookRight(float AxisValue);
    void ActionRightHand();
    void ActionLeftHand();
};
