// Copyright (C) 2016  Jens Pitkanen & Aleksi Talarmo

#include "HardlyGladiators.h"
#include "HGItem.h"

AHGItem::AHGItem() {
	PrimaryActorTick.bCanEverTick = true;
}

void AHGItem::BeginPlay() {
	Super::BeginPlay();
}

void AHGItem::Tick( float DeltaTime ) {
	Super::Tick( DeltaTime );
}

float AHGItem::CalculateWeight(UStaticMeshComponent *WeightyMesh, float Hollowness) {
    FVector Bounds = WeightyMesh->Bounds.BoxExtent;
    // 0.01f: cm => m, 2.0f: Halfextents to full extents
    Bounds *= 0.01f * 2.0f * (1.0f - Hollowness);
    float Volume = Bounds.X * Bounds.Y * Bounds.Z;
    float Density = WeightyMesh->GetMaterial(0)->GetPhysicalMaterial()->Density;
    return Volume * Density;
}
