// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PlayerInterface.generated.h"

UINTERFACE(MinimalAPI)
class UPlayerInterface : public UInterface
{
	GENERATED_BODY()
};

class OURA_API IPlayerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void AddToPlayerLevel(int32 InPlayerLevel);

	UFUNCTION(BlueprintNativeEvent)
	void AddToSpellPoints(int32 InSpellPoints);

	UFUNCTION(BlueprintNativeEvent)
	void AddToAttributePoints(int32 InAttributePoints);

	UFUNCTION(BlueprintNativeEvent)
	int32 GetAttributePoints() const;

	UFUNCTION(BlueprintNativeEvent)
	int32 GetAttributePointsReward(int32 Level) const;
};
