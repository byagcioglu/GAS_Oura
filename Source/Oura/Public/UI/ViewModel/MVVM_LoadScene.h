// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "MVVM_LoadScene.generated.h"

class UMVVM_LoadSlot;

UCLASS()
class OURA_API UMVVM_LoadScene : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	void InitializeLoadSlots();
	void SetNumLoadSlots(int32 InNumLoadSlots);
	int32 GetNumLoadSlots() const { return NumLoadSlots; }

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UMVVM_LoadSlot> LoadSlotViewModelClass;

	UFUNCTION(BlueprintPure)
	UMVVM_LoadSlot* GetLoadSlotViewModelByIndex(int32 Index) const;

	void LoadData();
	
private:
	UPROPERTY()
	TObjectPtr<UMVVM_LoadSlot> LoadSlot_0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, Setter, Getter, meta = (AllowPrivateAccess="true"));
	int32 NumLoadSlots=3;
};
