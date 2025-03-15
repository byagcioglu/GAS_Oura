// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ViewModel/MVVM_LoadScene.h"
#include "UI/ViewModel/MVVM_LoadSlot.h"


void UMVVM_LoadScene::InitializeLoadSlots()
{
	LoadSlot_0 = NewObject<UMVVM_LoadSlot>(this, LoadSlotViewModelClass);
	LoadSlot_0->InitializeSlot();
}

UMVVM_LoadSlot* UMVVM_LoadScene::GetLoadSlotViewModelByIndex(int32 Index) const
{
	return LoadSlot_0; //LoadSlots.FindChecked(Index);
}

void UMVVM_LoadScene::SetNumLoadSlots(int32 InNumLoadSlots)
{
	UE_MVVM_SET_PROPERTY_VALUE(NumLoadSlots, InNumLoadSlots);
}

void UMVVM_LoadScene::LoadData()
{
	
	LoadSlot_0->SetPlayerName(TEXT("BaranYagcioglu"));
	LoadSlot_0->InitializeSlot();
		
}