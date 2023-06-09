#pragma once

#include "TRTile.h"
#include "TRTileMap.h"
#include "TRWorldGeneration.h"
#include "CPlayer.h"
#include "CScene.h"

#include "TRItemContainer.h"

class TRItemContainer;
class CQuickBarVisualizer;
class CHealthIndicator;
class CInventoryVisualizer;

class TRWorld
{
public:
	static constexpr int WORLD_WIDTH = 512;
	static constexpr int WORLD_HEIGHT = 256;

private:
	TRTileMap* tile_map;
	CPlayer* player;

	TRItemContainer* player_inventory[50];
	TRItemContainer* quick_bar[10];

	CQuickBarVisualizer* quick_bar_visualizer;
	CInventoryVisualizer* inventory_visualizer;

	CHealthIndicator* health_indicator;
	int quick_bar_index;
	bool toggle_inventory;

public:
	TRWorld();
	~TRWorld();

	void Update();

	void CreateWorld(int seed);
	void OnSceneCreate(CScene* scene);

	static Vec2 WorldToGlobal(const Vec2& v);
	static Vec2 GlobalToWorld(const Vec2& v);

	TRTileMap* GetTileMap() const;
	CPlayer* GetPlayer() const;

	void SetToggleInventory(bool value);
	void AddItemToInventory(TRItemStack item);

	auto& GetQuickBarList() { return quick_bar; }
	int GetQuickBarIdx()const { return quick_bar_index; }
};