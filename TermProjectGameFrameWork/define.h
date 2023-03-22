#pragma once


#define fDT CTimeMgr::GetInst()->GetfDT()			
#define DT	CTimeMgr::GetInst()->GetDT()			

#define CLONE(type)  type* Clone()override{return new type{*this};} 

#define KEY_CHECK(key,state)	CKeyMgr::GetInst()->GetKeyState(key)==state
#define KEY_HOLD(key)			KEY_CHECK(key,KEY_STATE::HOLD)		
#define KEY_TAP(key)			KEY_CHECK(key,KEY_STATE::TAP)
#define KEY_AWAY(key)			KEY_CHECK(key,KEY_STATE::AWAY)
#define KEY_NONE(key)			KEY_CHECK(key,KEY_STATE::NONE)

#define MOUSE_POS CKeyMgr::GetInst()->GetMousePos()

#define PI	3.1415926535

#define TILE_SIZE 64 // Ÿ�� ������ �ȼ� ��ũ��

#define COMP_CLONE(type,owner)	type* Clone(owner* const _pOwner)const override {type* pNewComp = new type {*this}; pNewComp->SetOwner(_pOwner);return pNewComp;}

enum class GROUP_TYPE	
{
	DEFAULT,	
	TILE,		
	GROUND, 
	MONSTER,	
	PLAYER,		
	PROJ_PLAYER, 
	PROJ_MONSTER, 

	UI = 31,		
	
	END = 32, 
};

enum class SCENE_TYPE	
{
	TOOL,
	START,
	STAGE_01,
	STAGE_02,



	END,
};

enum class BRUSH_TYPE
{
	HOLLOW,
	BLACK, 
	WHITE,
	RED,
	GREEN,
	BLUE,

	END,
};

enum class PEN_TYPE
{
	BLACK,
	RED,
	GREEN,
	BLUE,

	END,
};

enum class EVENT_TYPE
{
	CREATE_OBJECT, 
	DELETE_OBJECT, 
	SCENE_CHANGE, 
	CHANGE_AI_STATE,
	END, 
};

enum class MON_STATE		
{
	IDLE,
	PATROL,
	TRACE,
	ATK,
	RUN,
	DEAD,
	END,
};

enum class COMPONENT_TYPE
{
	COLLIDER,
	ANIMATOR,
	RIGIDBODY,

	END,
};

#define CAST(type,expr)		(static_cast<type>(expr))
#define GET_COMP(type,Enum)		CAST(type,GetComponent(Enum))	
#define Mgr(type)	(type::GetInst())

enum class SOUND_TYPE
{
	WALK,
	ATTACK,
	JUMP,
	HIT,
	DIE,

	END
};