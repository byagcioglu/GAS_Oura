// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "Abilities/GameplayAbility.h"

void UAuraAbilitySystemComponent::AbilityInputTagHeld()
{
	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
        if (!AbilitySpec.IsActive())
        {
            TryActivateAbility(AbilitySpec.Handle);
        }
	}
}

void UAuraAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities)
{
	for (const TSubclassOf<UGameplayAbility> AbilityClass : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
		if (const UGameplayAbility* AuraAbility = AbilitySpec.Ability)
		{
			GiveAbility(AbilitySpec);
		}
	}
}