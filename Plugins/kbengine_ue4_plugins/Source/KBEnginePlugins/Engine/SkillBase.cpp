﻿#include "SkillBase.h"
#include "KBVar.h"
#include "EntityDef.h"
#include "ScriptModule.h"
#include "Property.h"
#include "Method.h"
#include "DataTypes.h"
#include "CustomDataTypes.h"
#include "MemoryStream.h"
#include "EntityComponent.h"

namespace KBEngine
{



void SkillBase::onComponentsEnterworld()
{
}

void SkillBase::onComponentsLeaveworld()
{
}

void SkillBase::onGetBase()
{
	if(pBaseEntityCall)
		delete pBaseEntityCall;

	pBaseEntityCall = new EntityBaseEntityCall_SkillBase(id(), className());
}

void SkillBase::onGetCell()
{
	if(pCellEntityCall)
		delete pCellEntityCall;

	pCellEntityCall = new EntityCellEntityCall_SkillBase(id(), className());
}

void SkillBase::onLoseCell()
{
	delete pCellEntityCall;
	pCellEntityCall = NULL;
}

EntityCall* SkillBase::getBaseEntityCall()
{
	return pBaseEntityCall;
}

EntityCall* SkillBase::getCellEntityCall()
{
	return pCellEntityCall;
}

void SkillBase::onRemoteMethodCall(MemoryStream& stream)
{
}

void SkillBase::onUpdatePropertys(MemoryStream& stream)
{
	ScriptModule* sm = *EntityDef::moduledefs.Find("Skill");

	while(stream.length() > 0)
	{
		uint16 componentPropertyUType = 0;
		uint16 properUtype = 0;

		if (sm->usePropertyDescrAlias)
		{
			componentPropertyUType = stream.readUint8();
			properUtype = stream.read<uint8>();
		}
		else
		{
			componentPropertyUType = stream.readUint16();
			properUtype = stream.read<uint16>();
		}

		if(componentPropertyUType > 0)
		{
			KBE_ASSERT(false);

			return;
		}

		Property* pProp = sm->idpropertys[properUtype];

		switch(pProp->properUtype)
		{
			case 40001:
			{
				FVector oldval_direction = direction;
				direction = stream.readVector3();

				if(pProp->isBase())
				{
					if(inited())
						onDirectionChanged(oldval_direction);
				}
				else
				{
					if(inWorld())
						onDirectionChanged(oldval_direction);
				}

				break;
			}
			case 40000:
			{
				FVector oldval_position = position;
				position = stream.readVector3();

				if(pProp->isBase())
				{
					if(inited())
						onPositionChanged(oldval_position);
				}
				else
				{
					if(inWorld())
						onPositionChanged(oldval_position);
				}

				break;
			}
			case 35:
			{
				uint8 oldval_skillId = skillId;
				skillId = stream.readUint8();

				if(pProp->isBase())
				{
					if(inited())
						onSkillIdChanged(oldval_skillId);
				}
				else
				{
					if(inWorld())
						onSkillIdChanged(oldval_skillId);
				}

				break;
			}
			case 40002:
			{
				stream.readUint32();
				break;
			}
			default:
				break;
		};
	}
}

void SkillBase::callPropertysSetMethods()
{
	ScriptModule* sm = EntityDef::moduledefs["Skill"];
	TMap<uint16, Property*>& pdatas = sm->idpropertys;

	FVector oldval_direction = direction;
	Property* pProp_direction = pdatas[2];
	if(pProp_direction->isBase())
	{
		if(inited() && !inWorld())
			onDirectionChanged(oldval_direction);
	}
	else
	{
		if(inWorld())
		{
			if(pProp_direction->isOwnerOnly() && !isPlayer())
			{
			}
			else
			{
				onDirectionChanged(oldval_direction);
			}
		}
	}

	FVector oldval_position = position;
	Property* pProp_position = pdatas[1];
	if(pProp_position->isBase())
	{
		if(inited() && !inWorld())
			onPositionChanged(oldval_position);
	}
	else
	{
		if(inWorld())
		{
			if(pProp_position->isOwnerOnly() && !isPlayer())
			{
			}
			else
			{
				onPositionChanged(oldval_position);
			}
		}
	}

	uint8 oldval_skillId = skillId;
	Property* pProp_skillId = pdatas[4];
	if(pProp_skillId->isBase())
	{
		if(inited() && !inWorld())
			onSkillIdChanged(oldval_skillId);
	}
	else
	{
		if(inWorld())
		{
			if(pProp_skillId->isOwnerOnly() && !isPlayer())
			{
			}
			else
			{
				onSkillIdChanged(oldval_skillId);
			}
		}
	}

}

SkillBase::SkillBase():
	Entity(),
	pBaseEntityCall(NULL),
	pCellEntityCall(NULL),
	skillId((uint8)FCString::Atoi64(TEXT("0")))
{
}

SkillBase::~SkillBase()
{
	if(pBaseEntityCall)
		delete pBaseEntityCall;

	if(pCellEntityCall)
		delete pCellEntityCall;

}

void SkillBase::attachComponents()
{
}

void SkillBase::detachComponents()
{
}

}