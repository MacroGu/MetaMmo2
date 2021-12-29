﻿/*
	Generated by KBEngine!
	Please do not modify this file!
	Please inherit this module, such as: (class Ore : public OreBase)
	tools = kbcmd
*/

#pragma once
#include "KBECommon.h"
#include "Entity.h"
#include "KBETypes.h"
#include "EntityCallOreBase.h"

namespace KBEngine
{

class Method;
class Property;
class MemoryStream;

// defined in */scripts/entity_defs/Ore.def
	// Please inherit and implement "class Ore : public OreBase"
class KBENGINEPLUGINS_API OreBase : public Entity
{
public:
	EntityBaseEntityCall_OreBase* pBaseEntityCall;
	EntityCellEntityCall_OreBase* pCellEntityCall;

	uint8 digCount;
	virtual void onDigCountChanged(uint8 oldValue) {}
	uint32 oreID;
	virtual void onOreIDChanged(uint32 oldValue) {}


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

	OreBase();
	virtual ~OreBase();

	void attachComponents() override;
	void detachComponents() override;

};

}