﻿/*
	Generated by KBEngine!
	Please do not modify this file!
	
	tools = kbcmd
*/

#pragma once

#include "KBECommon.h"
#include "EntityCall.h"
#include "KBETypes.h"
#include "CustomDataTypes.h"


// defined in */scripts/entity_defs/Skill.def

namespace KBEngine
{

class KBENGINEPLUGINS_API EntityBaseEntityCall_SkillBase : public EntityCall
{
public:

	EntityBaseEntityCall_SkillBase(int32 eid, const FString& ename);

	virtual ~EntityBaseEntityCall_SkillBase();
};

class KBENGINEPLUGINS_API EntityCellEntityCall_SkillBase : public EntityCall
{
public:

	EntityCellEntityCall_SkillBase(int32 eid, const FString& ename);

	virtual ~EntityCellEntityCall_SkillBase();
};

}