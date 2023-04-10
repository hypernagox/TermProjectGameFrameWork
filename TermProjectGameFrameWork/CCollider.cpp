#include "pch.h"
#include "CCollider.h"
#include "CObject.h"
#include "CCamera.h"
#include "CCore.h"

UINT	CCollider::g_iNextID = 0;


CCollider::CCollider()
	:m_iID{g_iNextID++}
{
}

CCollider::~CCollider()
{
}

CCollider::CCollider(const CCollider& _other)
	:CComponent{ _other }
	, m_vOffsetPos{ _other.m_vOffsetPos }
	, m_vScale{ _other.m_vScale }
	, m_vFinalPos{ _other.m_vFinalPos }
	, m_iColCnt{ 0 }
	, m_iID{ g_iNextID++ }
{

}

void CCollider::component_update()
{
	const Vec2 vObjectPos = m_pOwner->GetPos();
	m_vScale = m_pOwner->GetScale();
	m_vFinalPos = vObjectPos + m_vOffsetPos;
}

void CCollider::component_render(HDC _dc)const
{
	Vec2 vRenderPos = CCamera::GetInst()->GetRenderPos(m_vFinalPos);
	//Mgr(CCore)->ChangeBrush(BRUSH_TYPE::HOLLOW);
	Rectangle(_dc
		, (int)(vRenderPos.x - m_vScale.x / 2.)
		, (int)(vRenderPos.y - m_vScale.y / 2.)
		, (int)(vRenderPos.x + m_vScale.x / 2.)
		, (int)(vRenderPos.y + m_vScale.y / 2.));
		/*m_vScale = m_pOwner->GetScale();
		Rectangle(_dc
			, (int)(m_vFinalPos.x - m_vScale.x / 2.)
			, (int)(m_vFinalPos.y - m_vScale.y / 2.)
			, (int)(m_vFinalPos.x + m_vScale.x / 2.)
			, (int)(m_vFinalPos.y + m_vScale.y / 2.));*/

}

void CCollider::OnCollision(CCollider* const _pOther)
{
	m_pOwner->OnCollision(_pOther);
}

void CCollider::OnCollisionEnter(CCollider* const _pOther)
{
	++m_iColCnt;
	m_pOwner->OnCollisionEnter(_pOther);
}

void CCollider::OnCollisionExit(CCollider* const _pOther)
{
	--m_iColCnt;
	m_pOwner->OnCollisionExit(_pOther);
}
