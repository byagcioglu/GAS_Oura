// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ViewModel/MVVM_LoadScene.h"
#include "UI/ViewModel/MVVM_LoadSlot.h"


void UMVVM_LoadScene::InitializeLoadSlots()
{
	LoadSlot_0 = NewObject<UMVVM_LoadSlot>(this, LoadSlotViewModelClass);
	LoadSlot_0->SlotIndex = 0;
	LoadSlots.Add(0, LoadSlot_0);
	LoadSlot_0->InitializeSlot();

	LoadSlot_1 = NewObject<UMVVM_LoadSlot>(this, LoadSlotViewModelClass);
	LoadSlot_0->SlotIndex = 1;
	LoadSlots.Add(1, LoadSlot_1);
	LoadSlot_1->InitializeSlot();

	LoadSlot_2 = NewObject<UMVVM_LoadSlot>(this, LoadSlotViewModelClass);
	LoadSlot_0->SlotIndex = 2;
	LoadSlots.Add(2, LoadSlot_2);
	LoadSlot_2->InitializeSlot();
}

UMVVM_LoadSlot* UMVVM_LoadScene::GetLoadSlotViewModelByIndex(int32 Index) const
{
	return LoadSlots.FindChecked(Index);
}

void UMVVM_LoadScene::SetNumLoadSlots(int32 InNumLoadSlots)
{
	UE_MVVM_SET_PROPERTY_VALUE(NumLoadSlots, InNumLoadSlots);
}

void UMVVM_LoadScene::LoadData()
{
	
	LoadSlot_0->SetPlayerName(TEXT("BaranYagcioglu"));
	LoadSlot_0->SlotStatus = Vacant;
	LoadSlot_0->InitializeSlot();
		
}

void UMVVM_LoadScene::NewGameButtonPressed(int32 Slot)
{
	LoadSlots[Slot]->SetWidgetSwitcherIndex.Broadcast(1);
}

void UMVVM_LoadScene::NewSlotButtonPressed(int32 Slot, const FString& EnteredName)
{

	LoadSlots[Slot]->SetPlayerName(EnteredName);
	LoadSlots[Slot]->SetPlayerLevel(1);
	LoadSlots[Slot]->SlotStatus = Taken;

	LoadSlots[Slot]->InitializeSlot();

}