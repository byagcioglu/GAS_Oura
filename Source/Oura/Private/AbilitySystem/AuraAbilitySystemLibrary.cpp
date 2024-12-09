// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystem/AuraAbilitySystemLibrary.h"
#include "AuraAbilityTypes.h"
#include "GameplayEffectTypes.h"
#include "AbilitySystemComponent.h"


FGameplayEffectContextHandle UAuraAbilitySystemLibrary::ApplyDamageEffect(const FDamageEffectParams& DamageEffectParams)
{
	const AActor* SourceAvatarActor = DamageEffectParams.SourceAbilitySystemComponent->GetAvatarActor();
    FGameplayEffectContextHandle EffectContexthandle = DamageEffectParams.SourceAbilitySystemComponent->MakeEffectContext();
    EffectContexthandle.AddSourceObject(SourceAvatarActor);
    const FGameplayEffectSpecHandle SpecHandle = DamageEffectParams.SourceAbilitySystemComponent
            ->MakeOutgoingSpec(DamageEffectParams.DamageGameplayEffectClass, 1.f, EffectContexthandle);
    DamageEffectParams.TargetAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data);
    return EffectContexthandle;
}

