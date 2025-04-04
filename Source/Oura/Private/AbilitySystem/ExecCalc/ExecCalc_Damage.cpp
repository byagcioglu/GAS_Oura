// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ExecCalc/ExecCalc_Damage.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/AuraAbilitySystemLibrary.h"
#include "AuraGameplayTags.h"


void UExecCalc_Damage::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
                                              FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
    const FAuraGameplayTags& GameplayTags = FAuraGameplayTags::Get();

    const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();
    FGameplayEffectContextHandle ContextHandle = Spec.GetContext();
	UAuraAbilitySystemLibrary::SetIsSuccessfulDebuff(ContextHandle, true);

    const float DebuffDamage = Spec.GetSetByCallerMagnitude(GameplayTags.Debuff_Damage, false, -1.f);
    const float DebuffDuration = Spec.GetSetByCallerMagnitude(GameplayTags.Debuff_Duration, false, -1.f);
    const float DebuffFrequency = Spec.GetSetByCallerMagnitude(GameplayTags.Debuff_Frequency, false, -1.f);

    UAuraAbilitySystemLibrary::SetDebuffDamage(ContextHandle, DebuffDamage);
    UAuraAbilitySystemLibrary::SetDebuffDuration(ContextHandle, DebuffDuration);
    UAuraAbilitySystemLibrary::SetDebuffFrequency(ContextHandle, DebuffFrequency);

    float Damage = 11.f;
    const FGameplayModifierEvaluatedData EvaluatedData(UAuraAttributeSet::GetIncomingDamageAttribute(), EGameplayModOp::Additive, Damage);
	OutExecutionOutput.AddOutputModifier(EvaluatedData);
}