/*
	Generated by KBEngine!
	Please do not modify this file!
	Please inherit this module, such as: (class SceneMgr : public SceneMgrBase)
	tools = kbcmd
*/

#pragma once
#include "KBECommon.h"
#include "Entity.h"
#include "KBETypes.h"
#include "EntityCallSceneMgrBase.h"

namespace KBEngine
{

class Method;
class Property;
class MemoryStream;

// defined in */scripts/entity_defs/SceneMgr.def
	// Please inherit and implement "class SceneMgr : public SceneMgrBase"
class KBENGINEPLUGINS_API SceneMgrBase : public Entity
{
public:
	EntityBaseEntityCall_SceneMgrBase* pBaseEntityCall;
	EntityCellEntityCall_SceneMgrBase* pCellEntityCall;



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

	SceneMgrBase();
	virtual ~SceneMgrBase();

	void attachComponents() override;
	void detachComponents() override;

};

}