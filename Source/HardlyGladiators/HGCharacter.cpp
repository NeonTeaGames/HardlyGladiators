// Copyright (C) 2016  Jens Pitkanen & Aleksi Talarmo

#include "HardlyGladiators.h"
#include "HGCharacter.h"

AHGCharacter::AHGCharacter() {
	PrimaryActorTick.bCanEverTick = true;

	this->Vitalities = TMap<FName, float>();
	this->CriticalBodyParts = TArray<FName>();
	this->Blood = 5;
}

void AHGCharacter::BeginPlay() {
	Super::BeginPlay();
	this->ResetVitalitiesToCurrentSkeleton();
}

void AHGCharacter::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);

	if (this->Dead) {
		return;
	}

	this->Blood += 0.01 * DeltaTime; // Regen 1 cl blood every second
	
	for (auto &Vitality : this->Vitalities) {
		float Damage = this->MaxVitality - Vitality.Value;
		float Lost = Damage / 2000 * DeltaTime;
		if (this->CriticalBodyParts.Contains(Vitality.Key)) {
			Lost *= 2;
		}
		this->Blood -= Lost;
	}

	if (!this->Fainted && this->Blood <= 1.5) {
		this->Fainted = true;
		this->OnFaint();
	}
	else if (this->Fainted && this->Blood >= 3) {
		this->Fainted = false;
		this->OnWake();
	}

	if (this->Blood <= 0) {
		this->Die();
	}

	this->Blood = fmin(this->Blood, this->MaxBlood);
}

// Set which body parts are critical
void AHGCharacter::setCriticalBodyParts(TArray<FName> CriticalBodyParts) {
	this->CriticalBodyParts = CriticalBodyParts;
}

// Deal damage to a specified body part
void AHGCharacter::DealDamageToBodyPart(FName BodyPartName, float Damage) {
	float *Current = this->Vitalities.Find(BodyPartName);
	if (Current != nullptr) {
		float Result = *Current - Damage;
		this->Vitalities.Add(BodyPartName, *Current - Damage);
		UE_LOG(LogTemp, Warning, TEXT("Bodypart '%s' now only has %f health left :("), *BodyPartName.ToString(), Result);
		this->OnBodyPartTakeDamage(BodyPartName, Damage);

		if (Result <= 0) {
			this->OnBodyPartDie(BodyPartName, Damage);

			if (this->CriticalBodyParts.Contains(BodyPartName)) {
				this->Die();
			}
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("I don't have a bone called %s!"), *BodyPartName.ToString());
	}
}

// Get vitality of the specified body part
float AHGCharacter::GetBodyPartVitality(FName BodyPartName) {
	float *Current = this->Vitalities.Find(BodyPartName);
	if (Current != nullptr) {
		return *Current;
	}
	return -1;
}

// Remove body part from the vitalities
void AHGCharacter::RemoveBodyPartFromVitalities(FName BodyPartName) {
	this->Vitalities.Remove(BodyPartName);
}

// Add the body part to vitalities or set it's vitality to 100
float AHGCharacter::AddOrRefreshVitality(FName BodyPartName) {
	this->Vitalities.Add(BodyPartName, this->MaxVitality);
	return 100;
}

// Remove all vitalities and add new ones from current bones with default health of 100
void AHGCharacter::ResetVitalitiesToCurrentSkeleton() {
	this->Vitalities = TMap<FName, float>();

	USkeletalMeshComponent *SkeletalMesh = Cast<USkeletalMeshComponent>
		(this->GetComponentByClass(USkeletalMeshComponent::StaticClass()));
	TArray<FName> Names;
	SkeletalMesh->GetBoneNames(Names);

	for (int Counter = 0; Counter < Names.Num(); Counter++) {
		this->Vitalities.Add(Names[Counter], this->MaxVitality);
	}
}

float AHGCharacter::GetCurrentBlood() {
	return this->Blood;
}

void AHGCharacter::Die() {
	this->Dead = true;
	this->OnDie();
}