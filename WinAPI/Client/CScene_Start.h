#pragma once
#include "CScene.h"

class CScene_Start :
	public CScene
{
public:
	void Enter() override;
	void Exit() override;
	void update() override;

public:
	CScene_Start();
	~CScene_Start();
};

