// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Data/LootTiers.h"

TArray<FLootItem> ULootTiers::GetLootItems()
{
	TArray<FLootItem> ReturnItems;

    ReturnItems.Add(LootItems[FMath::FRandRange(0.f, LootItems.Num())]);

	return ReturnItems;
}