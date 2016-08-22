// Copyright (C) 2016  Jens Pitkanen & Aleksi Talarmo

#pragma once

#include "GameFramework/PlayerController.h"
#include "HGPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class HARDLYGLADIATORS_API AHGPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, Category="Movement Input")
    void MoveForward(float AxisValue);
    UFUNCTION(BlueprintCallable, Category="Movement Input")
    void MoveRight(float AxisValue);
    UFUNCTION(BlueprintCallable, Category="Movement Input")
    void LookUp(float AxisValue);
    UFUNCTION(BlueprintCallable, Category="Movement Input")
    void LookRight(float AxisValue);
};
