#pragma once
#include "CScene.h"

class CScene_Start
	:public CScene
{
public:
	CScene_Start();
	~CScene_Start();
public:
	void Enter()override;
	void Exit()override;
	void update()override;
};
