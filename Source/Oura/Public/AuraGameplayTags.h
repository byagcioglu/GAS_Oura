// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

struct FAuraGameplayTags
{
public:
    static const FAuraGameplayTags& Get() { return GameplayTags;}
    static void InitializeNativeGameplayTags();

	FGameplayTag Abilities_Attack;

	FGameplayTag Montage_Attack_1;

	FGameplayTag Effects_HitReact;

    FGameplayTag Abilities_Fire_FireBolt;

private:
    static FAuraGameplayTags GameplayTags;

};