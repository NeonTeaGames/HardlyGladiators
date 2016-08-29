// Copyright (C) 2016  Jens Pitkanen & Aleksi Talarmo

#pragma once

#include "GameFramework/Character.h"
#include "HGCharacter.generated.h"

UCLASS()
class HARDLYGLADIATORS_API AHGCharacter : public ACharacter {
	GENERATED_BODY()

public:
	AHGCharacter();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;

    UFUNCTION(BlueprintImplementableEvent, Category="Character")
    void OnAction(bool LeftHandedAction);

	UFUNCTION(BlueprintImplementableEvent, Category = "Character")
	void OnBodyPartTakeDamage(FName BodyPartName, float Damage);

	UFUNCTION(BlueprintImplementableEvent, Category = "Character")
	void OnBodyPartDie(FName BodyPartName, float FatalDamage);

	UFUNCTION(BlueprintImplementableEvent, Category = "Character")
	void OnFaint();

	UFUNCTION(BlueprintImplementableEvent, Category = "Character")
	void OnWake();

	UFUNCTION(BlueprintImplementableEvent, Category = "Character")
	void OnDie();

	UFUNCTION(BlueprintCallable, Category = "Character")
	void setCriticalBodyParts(TArray<FName> CriticalBodyParts);

	UFUNCTION(BlueprintCallable, Category = "Character")
	void DealDamageToBodyPart(FName BodyPartName, float Damage);

	UFUNCTION(BlueprintCallable, Category = "Character")
	float GetBodyPartVitality(FName BodyPartName);

	UFUNCTION(BlueprintCallable, Category = "Character")
	void RemoveBodyPartFromVitalities(FName BodyPartName);

	UFUNCTION(BlueprintCallable, Category = "Character")
	float AddOrRefreshVitality(FName BodyPartName);

	UFUNCTION(BlueprintCallable, Category = "Character")
	void ResetVitalitiesToCurrentSkeleton();

	UFUNCTION(BlueprintCallable, Category = "Character")
	float GetCurrentBlood();

private:
	TMap<FName, float> Vitalities;
	TArray<FName> CriticalBodyParts;
	float Blood;

	bool Fainted = false;
	bool Dead = false;

	static const int MaxVitality = 100;
	static const int MaxBlood = 5;

	void Die();
};
