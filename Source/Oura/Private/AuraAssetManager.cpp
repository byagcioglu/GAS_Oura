// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraAssetManager.h"
#include "AbilitySystemGlobals.h"
#include "AuraGameplayTags.h"

UAuraAssetManager& UAuraAssetManager::Get()
{
	UAuraAssetManager* AuraAssetManager = Cast<UAuraAssetManager>(GEngine->AssetManager);
	return *AuraAssetManager;
}

void UAuraAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	FAuraGameplayTags::InitializeNativeGameplayTags();

	// This is required to use Target Data!
	UAbilitySystemGlobals::Get().InitGlobalData();
}
