// Copyright (C) 2016  Jens Pitkanen & Aleksi Talarmo

#pragma once

#include "GameFramework/Actor.h"
#include "HGItem.generated.h"

UCLASS()
class HARDLYGLADIATORS_API AHGItem : public AActor {
	GENERATED_BODY()
	
public:	
	AHGItem();
	virtual void BeginPlay() override;
	virtual void Tick( float DeltaSeconds ) override;

    UFUNCTION(BlueprintCallable, Category="Items")
    float CalculateWeight(UStaticMeshComponent *WeightyMesh, float Hollowness);
};
