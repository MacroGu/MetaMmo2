﻿/*
	Generated by KBEngine!
	Please do not modify this file!
	tools = kbcmd
*/

#pragma once
#include "KBECommon.h"
#include "KBETypes.h"
#include "MemoryStream.h"
#include "Bundle.h"
#include "DataTypes.h"
namespace KBEngine
{


class KBENGINEPLUGINS_API DATATYPE_STRING_LIST : DATATYPE_BASE
{
public:
	void createFromStreamEx(MemoryStream& stream, STRING_LIST& datas);
	void addToStreamEx(Bundle& stream, const STRING_LIST& v);
};


class KBENGINEPLUGINS_API DATATYPE_UINT16_LIST : DATATYPE_BASE
{
public:
	void createFromStreamEx(MemoryStream& stream, UINT16_LIST& datas);
	void addToStreamEx(Bundle& stream, const UINT16_LIST& v);
};


class KBENGINEPLUGINS_API DATATYPE_UINT64_LIST : DATATYPE_BASE
{
public:
	void createFromStreamEx(MemoryStream& stream, UINT64_LIST& datas);
	void addToStreamEx(Bundle& stream, const UINT64_LIST& v);
};


class KBENGINEPLUGINS_API DATATYPE_ENTITY_LIST : DATATYPE_BASE
{
public:
	void createFromStreamEx(MemoryStream& stream, ENTITY_LIST& datas);
	void addToStreamEx(Bundle& stream, const ENTITY_LIST& v);
};


class KBENGINEPLUGINS_API DATATYPE_ITEM : DATATYPE_BASE
{
public:
	void createFromStreamEx(MemoryStream& stream, ITEM& datas);
	void addToStreamEx(Bundle& stream, const ITEM& v);
};


class KBENGINEPLUGINS_API DATATYPE_ITEM_LIST : DATATYPE_BASE
{
public:
	DATATYPE_ITEM itemType;

	void createFromStreamEx(MemoryStream& stream, ITEM_LIST& datas);
	void addToStreamEx(Bundle& stream, const ITEM_LIST& v);
};


class KBENGINEPLUGINS_API DATATYPE_CHAT_INFO : DATATYPE_BASE
{
public:
	void createFromStreamEx(MemoryStream& stream, CHAT_INFO& datas);
	void addToStreamEx(Bundle& stream, const CHAT_INFO& v);
};


class KBENGINEPLUGINS_API DATATYPE_SKILL_INFO : DATATYPE_BASE
{
public:
	void createFromStreamEx(MemoryStream& stream, SKILL_INFO& datas);
	void addToStreamEx(Bundle& stream, const SKILL_INFO& v);
};


class KBENGINEPLUGINS_API DATATYPE_AVATAR_BRIEF_INFO : DATATYPE_BASE
{
public:
	void createFromStreamEx(MemoryStream& stream, AVATAR_BRIEF_INFO& datas);
	void addToStreamEx(Bundle& stream, const AVATAR_BRIEF_INFO& v);
};


class KBENGINEPLUGINS_API DATATYPE_AVATAR_BRIEF_INFO_LIST : DATATYPE_BASE
{
public:
	DATATYPE_AVATAR_BRIEF_INFO itemType;

	void createFromStreamEx(MemoryStream& stream, AVATAR_BRIEF_INFO_LIST& datas);
	void addToStreamEx(Bundle& stream, const AVATAR_BRIEF_INFO_LIST& v);
};


class KBENGINEPLUGINS_API DATATYPE_ANIM_INFO : DATATYPE_BASE
{
public:
	void createFromStreamEx(MemoryStream& stream, ANIM_INFO& datas);
	void addToStreamEx(Bundle& stream, const ANIM_INFO& v);
};


}