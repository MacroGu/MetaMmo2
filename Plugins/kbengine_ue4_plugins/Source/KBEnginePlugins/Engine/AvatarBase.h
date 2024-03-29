﻿/*
	Generated by KBEngine!
	Please do not modify this file!
	Please inherit this module, such as: (class Avatar : public AvatarBase)
	tools = kbcmd
*/

#pragma once
#include "KBECommon.h"
#include "Entity.h"
#include "KBETypes.h"
#include "EntityCallAvatarBase.h"

namespace KBEngine
{

class Method;
class Property;
class MemoryStream;

// defined in */scripts/entity_defs/Avatar.def
	// Please inherit and implement "class Avatar : public AvatarBase"
class KBENGINEPLUGINS_API AvatarBase : public Entity
{
public:
	EntityBaseEntityCall_AvatarBase* pBaseEntityCall;
	EntityCellEntityCall_AvatarBase* pCellEntityCall;

	int32 BaseHP;
	virtual void onBaseHPChanged(int32 oldValue) {}
	int32 HP;
	virtual void onHPChanged(int32 oldValue) {}
	uint16 bagSize;
	virtual void onBagSizeChanged(uint16 oldValue) {}
	uint64 dbid;
	virtual void onDbidChanged(uint64 oldValue) {}
	int32 enage;
	virtual void onEnageChanged(int32 oldValue) {}
	TArray<uint8> facade;
	virtual void onFacadeChanged(const TArray<uint8>& oldValue) {}
	int8 isJump;
	virtual void onIsJumpChanged(int8 oldValue) {}
	int8 moveH;
	virtual void onMoveHChanged(int8 oldValue) {}
	int8 moveLevel;
	virtual void onMoveLevelChanged(int8 oldValue) {}
	int8 moveV;
	virtual void onMoveVChanged(int8 oldValue) {}
	FString name;
	virtual void onNameChanged(const FString& oldValue) {}
	uint16 netDelay;
	virtual void onNetDelayChanged(uint16 oldValue) {}
	uint32 serverTime;
	virtual void onServerTimeChanged(uint32 oldValue) {}
	uint8 sex;
	virtual void onSexChanged(uint8 oldValue) {}

	virtual void OnAnimUpdate(const ANIM_INFO& arg1) = 0; 
	virtual void OnAttack(const SKILL_INFO& arg1) = 0; 
	virtual void ntfError(uint32 arg1) = 0; 
	virtual void ntfItemsChange(const ITEM_LIST& arg1, const UINT16_LIST& arg2) = 0; 
	virtual void ntfReceiveChat(const CHAT_INFO& arg1) = 0; 
	virtual void rspChangeName(uint32 arg1) = 0; 
	virtual void rspDigOre() = 0; 
	virtual void rspStopDigOre() = 0; 
	virtual void rspSwitchAvatar(uint32 arg1) = 0; 

	void onComponentsEnterworld() override;
	void onComponentsLeaveworld() override;

	void onGetBase() override;
	void onGetCell() override;
	void onLoseCell() override;

	EntityCall* getBaseEntityCall() override;
	EntityCall* getCellEntityCall() override;


	void onRemoteMethodCall(MemoryStream& stream) override;
	void onUpdatePropertys(MemoryStream& stream) override;
	void callPropertysSetMethods() override;

	AvatarBase();
	virtual ~AvatarBase();

	void attachComponents() override;
	void detachComponents() override;

};

}