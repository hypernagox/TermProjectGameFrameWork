#include "pch.h"
#include "TRWorld.h"
#include "TRTileWall.h"
#include "CAtlasMgr.h"
#include "CustomMath.hpp"
#include <random>

TRTileWall::TRTileWall(std::wstring name, std::wstring k_element, std::wstring k_dropitem)
{
	this->name = name;
	this->k_element = k_element;
	this->k_dropitem = k_dropitem;

	if (k_element != L"")
		CreateAtlasElements();
}

void TRTileWall::CreateAtlasElements()
{
    for (int i = 0; i < 13; ++i)
    {
        for (int j = 0; j < 5; ++j)
            elements[i][j] = Mgr(CAtlasMgr)->GetAtlasElement(k_element, { i * 18.0f, j * 18.0f }, { 16.0f, 16.0f });
    }
}

void TRTileWall::OnDrawElement(CTileLayer* tilemap_layer, int x, int y, int bitmask, const RECT& clip)
{
	if (k_element == L"")
		return;

	static std::default_random_engine dre;
	static std::uniform_int_distribution<int> uid;

	int si = 0;
    int sj = 0;
    int sr = uid(dre) % 3;

    int loword = bitmask & 15;

    switch (loword)
    {
    case 0b00000000:
        si = 3;
        sj = 9 + sr;
        break;
    case 0b00000001:
        si = 3;
        sj = 6 + sr;
        break;
    case 0b00000010:
        si = 0;
        sj = 6 + sr;
        break;
    case 0b00000011:
        si = sr;
        sj = 5;
        break;
    case 0b00000100:
        si = sr;
        sj = 12;
        break;
    case 0b00000101:
        si = 4;
        sj = 1 + sr * 2;
        break;
    case 0b00000110:
        si = 3;
        sj = 1 + sr * 2;
        break;
    case 0b00000111:
        si = sr;
        sj = 4;
        break;
    case 0b00001000:
        si = sr;
        sj = 9;
        break;
    case 0b00001001:
        si = 4;
        sj = sr * 2;
        break;
    case 0b00001010:
        si = 3;
        sj = sr * 2;
        break;
    case 0b00001011:
        si = sr;
        sj = 0;
        break;
    case 0b00001100:
        si = 4;
        sj = 6 + sr;
        break;
    case 0b00001101:
        si = 2;
        sj = 1 + sr;
        break;
    case 0b00001110:
        si = 0;
        sj = 1 + sr;
        break;
    default:
        si = 1;
        sj = 1 + sr;
        break;
    }

    Vec2 s_pos = Vec2(clip.left - 1, clip.top - 1) * 8.0f;
    Vec2 s_size = Vec2((clip.right - clip.left) * 16 - 8, (clip.bottom - clip.top) * 16 - 8);

	tilemap_layer->pre_render(elements[sj][si], TRWorld::WorldToGlobal(Vec2(x, y + 1)) + s_pos, s_size);
}
