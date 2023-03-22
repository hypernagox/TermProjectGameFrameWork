#pragma once
#include "CComponent.h"

class CObject;

class CCollider
	:public CComponent
{
	static UINT		g_iNextID;
private:
	CCollider(const CCollider& _other);
	CCollider& operator = (const CCollider&) = delete;
public:
	CCollider();
	~CCollider();
private:
	Vec2				m_vOffsetPos = {};	
	Vec2				m_vFinalPos = {}; 
	Vec2				m_vScale = {};	
	UINT			m_iID = {};		
	int			m_iColCnt = {};
public:
	UINT GetID()const { return m_iID; }
	CCollider* Clone(CObject* const _pOwner)const override
	{
		CCollider* pNewComp = new CCollider{ *this };
		pNewComp->SetOwner(_pOwner);
		return pNewComp;
	}
	Vec2 GetFinalPos()const { return m_vFinalPos; } 
	void SetOffsetPos(Vec2 _vPos) { m_vOffsetPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }
	Vec2 GetOffsetPos()const { return m_vOffsetPos; }
	Vec2 GetScale()const { return m_vScale; }
public:
	void component_update()override;
	void component_render(HDC _dc)override;
public:
	void OnCollision(CCollider* const _pOther);	
	void OnCollisionEnter(CCollider* const _pOther);
	void OnCollisionExit(CCollider* const _pOther);
};

