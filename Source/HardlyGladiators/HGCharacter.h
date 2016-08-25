// Copyright (C) 2016  Jens Pitkanen & Aleksi Talarmo

#pragma once

#include "GameFramework/Character.h"
#include "HGCharacter.generated.h"

UCLASS()
class HARDLYGLADIATORS_API AHGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AHGCharacter();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;

    UFUNCTION(BlueprintImplementableEvent, Category="Character")
    void OnAction();
};
