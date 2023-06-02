#include "pch.h"
#include "CTileLayer.h"
#include "CResMgr.h"
#include "CAtlasMgr.h"
#include "CAtlasElement.h"
#include "CCamera.h"
#include "CCore.h"


CTileLayer::CTileLayer(Vec2 _vWorldPos ,UINT _iWidth, UINT _iHeight)
{
	SetScale(Vec2{ (float)_iWidth,(float)_iHeight});
	SetPos(_vWorldPos);
	CreateDCBITMAP(m_hTileLayerDC, m_hTileLayerBit, GetScale());
	SetStretchBltMode(m_hTileLayerDC, HALFTONE);
	m_vTileLayerScale = Vec2{ (float)_iWidth,(float)_iHeight };
}

CTileLayer::~CTileLayer()
{
	DeleteDCBITMAP(m_hTileLayerDC, m_hTileLayerBit);
}

void CTileLayer::pre_render(wstring_view _wstrFileName, Vec2 _vLayerLTPos, Vec2 _vScale, Vec2 _vBitPos, Vec2 _vSliceSize)
{
	auto pAtlasEle = Mgr(CAtlasMgr)->GetAtlasElement(_wstrFileName, _vBitPos, _vSliceSize);
	pAtlasEle->render(m_hTileLayerDC, _vLayerLTPos, _vScale);
}

void CTileLayer::pre_render(CAtlasElement* const _pElement, Vec2 _vLayerLTPos, Vec2 _vScale)
{
	_pElement->render(m_hTileLayerDC, _vLayerLTPos, _vScale);
}

void CTileLayer::render(HDC _dc)const
{
	const auto vOriginScale = GetScale();
	const Vec2 vLTpos = Mgr(CCamera)->GetRenderPos(GetPos() - vOriginScale / 2);
	
	TransparentBltSafe(_dc
		, static_cast<short>(vLTpos.x)
		, static_cast<short>(vLTpos.y + 800.f * 8.f)
		, static_cast<short>(vOriginScale.x)
		, static_cast<short>(vOriginScale.y)
		, m_hTileLayerDC
		, 0
		, 0
		, static_cast<short>(vOriginScale.x)
		, static_cast<short>(vOriginScale.y)
		, static_cast<short>(vOriginScale.x)
		, static_cast<short>(vOriginScale.y)
		, RGB(255, 0, 255));

}


