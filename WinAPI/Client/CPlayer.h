#pragma once
#include "CObject.h"

class CTexture;

class CPlayer : 
	public CObject
{

public:
	void update() override;
	void render(HDC _dc) override;
	CPlayer* Clone() override { return new CPlayer(*this); } 

	void CreateMissile();

public:
	CPlayer();
	~CPlayer();
};

