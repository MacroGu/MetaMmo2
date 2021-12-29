#include "ExRoleBase.h"
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



void ExRoleBase::onComponentsEnterworld()
{
}

void ExRoleBase::onComponentsLeaveworld()
{
}

void ExRoleBase::onGetBase()
{
	if(pBaseEntityCall)
		delete pBaseEntityCall;

	pBaseEntityCall = new EntityBaseEntityCall_ExRoleBase(id(), className());
}

void ExRoleBase::onGetCell()
{
	if(pCellEntityCall)
		delete pCellEntityCall;

	pCellEntityCall = new EntityCellEntityCall_ExRoleBase(id(), className());
}

void ExRoleBase::onLoseCell()
{
	delete pCellEntityCall;
	pCellEntityCall = NULL;
}

EntityCall* ExRoleBase::getBaseEntityCall()
{
	return pBaseEntityCall;
}

EntityCall* ExRoleBase::getCellEntityCall()
{
	return pCellEntityCall;
}

void ExRoleBase::onRemoteMethodCall(MemoryStream& stream)
{
	ScriptModule* sm = *EntityDef::moduledefs.Find("ExRole");
	uint16 methodUtype = 0;
	uint16 componentPropertyUType = 0;

	if (sm->usePropertyDescrAlias)
	{
		componentPropertyUType = stream.readUint8();
	}
	else
	{
		componentPropertyUType = stream.readUint16();
	}

	if (sm->useMethodDescrAlias)
	{
		methodUtype = stream.read<uint8>();
	}
	else
	{
		methodUtype = stream.read<uint16>();
	}

	if(componentPropertyUType > 0)
	{
		KBE_ASSERT(false);

		return;
	}

	Method* pMethod = sm->idmethods[methodUtype];

	switch(pMethod->methodUtype)
	{
		case 28:
		{
			CHAT_LIST AcceptChatList_arg1;
			((DATATYPE_CHAT_LIST*)pMethod->args[0])->createFromStreamEx(stream, AcceptChatList_arg1);
			AcceptChatList(AcceptChatList_arg1);
			break;
		}
		case 39:
		{
			ANIM_INFO OnAnimUpdate_arg1;
			((DATATYPE_ANIM_INFO*)pMethod->args[0])->createFromStreamEx(stream, OnAnimUpdate_arg1);
			OnAnimUpdate(OnAnimUpdate_arg1);
			break;
		}
		case 37:
		{
			OnAttack();
			break;
		}
		case 25:
		{
			uint8 OnIncreaseGood_arg1 = stream.readUint8();
			GOOD_INFO OnIncreaseGood_arg2;
			((DATATYPE_GOOD_INFO*)pMethod->args[1])->createFromStreamEx(stream, OnIncreaseGood_arg2);
			OnIncreaseGood(OnIncreaseGood_arg1, OnIncreaseGood_arg2);
			break;
		}
		case 27:
		{
			uint8 OnPassGood_arg1 = stream.readUint8();
			GOOD_INFO OnPassGood_arg2;
			((DATATYPE_GOOD_INFO*)pMethod->args[1])->createFromStreamEx(stream, OnPassGood_arg2);
			uint8 OnPassGood_arg3 = stream.readUint8();
			GOOD_INFO OnPassGood_arg4;
			((DATATYPE_GOOD_INFO*)pMethod->args[3])->createFromStreamEx(stream, OnPassGood_arg4);
			OnPassGood(OnPassGood_arg1, OnPassGood_arg2, OnPassGood_arg3, OnPassGood_arg4);
			break;
		}
		case 26:
		{
			uint8 OnReduceGood_arg1 = stream.readUint8();
			uint8 OnReduceGood_arg2 = stream.readUint8();
			GOOD_INFO OnReduceGood_arg3;
			((DATATYPE_GOOD_INFO*)pMethod->args[2])->createFromStreamEx(stream, OnReduceGood_arg3);
			OnReduceGood(OnReduceGood_arg1, OnReduceGood_arg2, OnReduceGood_arg3);
			break;
		}
		case 24:
		{
			BAG_INFO OnReqBagList_arg1;
			((DATATYPE_BAG_INFO*)pMethod->args[0])->createFromStreamEx(stream, OnReqBagList_arg1);
			BAG_INFO OnReqBagList_arg2;
			((DATATYPE_BAG_INFO*)pMethod->args[1])->createFromStreamEx(stream, OnReqBagList_arg2);
			BAG_INFO OnReqBagList_arg3;
			((DATATYPE_BAG_INFO*)pMethod->args[2])->createFromStreamEx(stream, OnReqBagList_arg3);
			BAG_INFO OnReqBagList_arg4;
			((DATATYPE_BAG_INFO*)pMethod->args[3])->createFromStreamEx(stream, OnReqBagList_arg4);
			OnReqBagList(OnReqBagList_arg1, OnReqBagList_arg2, OnReqBagList_arg3, OnReqBagList_arg4);
			break;
		}
		case 30:
		{
			FString ShowResultList_arg1 = stream.readUnicode();
			uint32 ShowResultList_arg2 = stream.readUint32();
			FString ShowResultList_arg3 = stream.readUnicode();
			uint32 ShowResultList_arg4 = stream.readUint32();
			FString ShowResultList_arg5 = stream.readUnicode();
			uint32 ShowResultList_arg6 = stream.readUint32();
			ShowResultList(ShowResultList_arg1, ShowResultList_arg2, ShowResultList_arg3, ShowResultList_arg4, ShowResultList_arg5, ShowResultList_arg6);
			break;
		}
		case 29:
		{
			uint32 UpdateCountDown_arg1 = stream.readUint32();
			UpdateCountDown(UpdateCountDown_arg1);
			break;
		}
		default:
			break;
	};
}

void ExRoleBase::onUpdatePropertys(MemoryStream& stream)
{
	ScriptModule* sm = *EntityDef::moduledefs.Find("ExRole");

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
			case 12:
			{
				int32 oldval_BaseHP = BaseHP;
				BaseHP = stream.readInt32();

				if(pProp->isBase())
				{
					if(inited())
						onBaseHPChanged(oldval_BaseHP);
				}
				else
				{
					if(inWorld())
						onBaseHPChanged(oldval_BaseHP);
				}

				break;
			}
			case 14:
			{
				int32 oldval_Defense = Defense;
				Defense = stream.readInt32();

				if(pProp->isBase())
				{
					if(inited())
						onDefenseChanged(oldval_Defense);
				}
				else
				{
					if(inWorld())
						onDefenseChanged(oldval_Defense);
				}

				break;
			}
			case 13:
			{
				int32 oldval_HP = HP;
				HP = stream.readInt32();

				if(pProp->isBase())
				{
					if(inited())
						onHPChanged(oldval_HP);
				}
				else
				{
					if(inWorld())
						onHPChanged(oldval_HP);
				}

				break;
			}
			case 10:
			{
				FString oldval_Name = Name;
				Name = stream.readUnicode();

				if(pProp->isBase())
				{
					if(inited())
						onNameChanged(oldval_Name);
				}
				else
				{
					if(inWorld())
						onNameChanged(oldval_Name);
				}

				break;
			}
			case 15:
			{
				float oldval_PowerRatio = PowerRatio;
				PowerRatio = stream.readFloat();

				if(pProp->isBase())
				{
					if(inited())
						onPowerRatioChanged(oldval_PowerRatio);
				}
				else
				{
					if(inWorld())
						onPowerRatioChanged(oldval_PowerRatio);
				}

				break;
			}
			case 11:
			{
				uint8 oldval_RoleType = RoleType;
				RoleType = stream.readUint8();

				if(pProp->isBase())
				{
					if(inited())
						onRoleTypeChanged(oldval_RoleType);
				}
				else
				{
					if(inWorld())
						onRoleTypeChanged(oldval_RoleType);
				}

				break;
			}
			case 4:
			{
				FVector oldval_SpawnPoint = SpawnPoint;
				SpawnPoint = stream.readVector3();

				if(pProp->isBase())
				{
					if(inited())
						onSpawnPointChanged(oldval_SpawnPoint);
				}
				else
				{
					if(inWorld())
						onSpawnPointChanged(oldval_SpawnPoint);
				}

				break;
			}
			case 16:
			{
				float oldval_SpeedRatio = SpeedRatio;
				SpeedRatio = stream.readFloat();

				if(pProp->isBase())
				{
					if(inited())
						onSpeedRatioChanged(oldval_SpeedRatio);
				}
				else
				{
					if(inWorld())
						onSpeedRatioChanged(oldval_SpeedRatio);
				}

				break;
			}
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

void ExRoleBase::callPropertysSetMethods()
{
	ScriptModule* sm = EntityDef::moduledefs["ExRole"];
	TMap<uint16, Property*>& pdatas = sm->idpropertys;

	int32 oldval_BaseHP = BaseHP;
	Property* pProp_BaseHP = pdatas[4];
	if(pProp_BaseHP->isBase())
	{
		if(inited() && !inWorld())
			onBaseHPChanged(oldval_BaseHP);
	}
	else
	{
		if(inWorld())
		{
			if(pProp_BaseHP->isOwnerOnly() && !isPlayer())
			{
			}
			else
			{
				onBaseHPChanged(oldval_BaseHP);
			}
		}
	}

	int32 oldval_Defense = Defense;
	Property* pProp_Defense = pdatas[5];
	if(pProp_Defense->isBase())
	{
		if(inited() && !inWorld())
			onDefenseChanged(oldval_Defense);
	}
	else
	{
		if(inWorld())
		{
			if(pProp_Defense->isOwnerOnly() && !isPlayer())
			{
			}
			else
			{
				onDefenseChanged(oldval_Defense);
			}
		}
	}

	int32 oldval_HP = HP;
	Property* pProp_HP = pdatas[6];
	if(pProp_HP->isBase())
	{
		if(inited() && !inWorld())
			onHPChanged(oldval_HP);
	}
	else
	{
		if(inWorld())
		{
			if(pProp_HP->isOwnerOnly() && !isPlayer())
			{
			}
			else
			{
				onHPChanged(oldval_HP);
			}
		}
	}

	FString oldval_Name = Name;
	Property* pProp_Name = pdatas[7];
	if(pProp_Name->isBase())
	{
		if(inited() && !inWorld())
			onNameChanged(oldval_Name);
	}
	else
	{
		if(inWorld())
		{
			if(pProp_Name->isOwnerOnly() && !isPlayer())
			{
			}
			else
			{
				onNameChanged(oldval_Name);
			}
		}
	}

	float oldval_PowerRatio = PowerRatio;
	Property* pProp_PowerRatio = pdatas[8];
	if(pProp_PowerRatio->isBase())
	{
		if(inited() && !inWorld())
			onPowerRatioChanged(oldval_PowerRatio);
	}
	else
	{
		if(inWorld())
		{
			if(pProp_PowerRatio->isOwnerOnly() && !isPlayer())
			{
			}
			else
			{
				onPowerRatioChanged(oldval_PowerRatio);
			}
		}
	}

	uint8 oldval_RoleType = RoleType;
	Property* pProp_RoleType = pdatas[9];
	if(pProp_RoleType->isBase())
	{
		if(inited() && !inWorld())
			onRoleTypeChanged(oldval_RoleType);
	}
	else
	{
		if(inWorld())
		{
			if(pProp_RoleType->isOwnerOnly() && !isPlayer())
			{
			}
			else
			{
				onRoleTypeChanged(oldval_RoleType);
			}
		}
	}

	FVector oldval_SpawnPoint = SpawnPoint;
	Property* pProp_SpawnPoint = pdatas[10];
	if(pProp_SpawnPoint->isBase())
	{
		if(inited() && !inWorld())
			onSpawnPointChanged(oldval_SpawnPoint);
	}
	else
	{
		if(inWorld())
		{
			if(pProp_SpawnPoint->isOwnerOnly() && !isPlayer())
			{
			}
			else
			{
				onSpawnPointChanged(oldval_SpawnPoint);
			}
		}
	}

	float oldval_SpeedRatio = SpeedRatio;
	Property* pProp_SpeedRatio = pdatas[11];
	if(pProp_SpeedRatio->isBase())
	{
		if(inited() && !inWorld())
			onSpeedRatioChanged(oldval_SpeedRatio);
	}
	else
	{
		if(inWorld())
		{
			if(pProp_SpeedRatio->isOwnerOnly() && !isPlayer())
			{
			}
			else
			{
				onSpeedRatioChanged(oldval_SpeedRatio);
			}
		}
	}

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

}

ExRoleBase::ExRoleBase():
	Entity(),
	pBaseEntityCall(NULL),
	pCellEntityCall(NULL),
	BaseHP((int32)FCString::Atoi64(TEXT("500"))),
	Defense((int32)FCString::Atoi64(TEXT("10"))),
	HP((int32)FCString::Atoi64(TEXT("500"))),
	Name(TEXT("")),
	PowerRatio(FCString::Atof(TEXT("1.0"))),
	RoleType((uint8)FCString::Atoi64(TEXT("0"))),
	SpawnPoint(),
	SpeedRatio(FCString::Atof(TEXT("1.0")))
{
}

ExRoleBase::~ExRoleBase()
{
	if(pBaseEntityCall)
		delete pBaseEntityCall;

	if(pCellEntityCall)
		delete pCellEntityCall;

}

void ExRoleBase::attachComponents()
{
}

void ExRoleBase::detachComponents()
{
}

}