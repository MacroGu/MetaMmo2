﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/BagWidget/MetaEquipBag.h"

void UMetaEquipBag::UpdateBlock(uint8 BlockId)
{
	Super::UpdateBlock(BlockId);

	// 根据物品信息是否存在和格子ID来设定装备显示和隐藏
	if (UMetaDataMgr::Get()->IsGoodExist(EBagType::EquipBag, BlockId))
	{
		switch (BlockId)
		{
		case 0:
			ChangeHelmet(true);
			break;
		case 1:
			ChangeArmor(true);
			break;
		case 2:
			ChangeShoes(true);
			break;
		default:
			break;
		}
	}
	else
	{
		switch (BlockId)
		{
		case 0:
			ChangeHelmet(false);
			break;
		case 1:
			ChangeArmor(false);
			break;
		case 2:
			ChangeShoes(false);
			break;
		default:
			break;
		}
	}

}

void UMetaEquipBag::SetBaseHp(int32 InBaseHp)
{
	ChangeHpText(FText::FromString(FString::FromInt(InBaseHp)));
}

void UMetaEquipBag::SetDefense(int32 InDefense)
{
	ChangeDefenseText(FText::FromString(FString::FromInt(InDefense)));
}

void UMetaEquipBag::SetPowerRatio(float InPowerRatio)
{
	FString PowerInfo = FString::FromInt(FMath::FloorToInt(InPowerRatio * 100)).Append("%");
	ChangePowerText(FText::FromString(PowerInfo));
}

void UMetaEquipBag::SetSpeedRatio(float InSpeedRatio)
{
	FString SpeedInfo = FString::FromInt(FMath::FloorToInt(InSpeedRatio * 100)).Append("%");
	ChangePowerText(FText::FromString(SpeedInfo));
}
