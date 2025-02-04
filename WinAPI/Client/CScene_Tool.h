#pragma once
#include "CScene.h"
class CScene_Tool :
    public CScene
{

public:
	void Enter() override;
	void Exit() override;
	void update() override;

public:
	CScene_Tool();
	~CScene_Tool();
};

