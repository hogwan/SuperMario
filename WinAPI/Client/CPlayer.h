#pragma once
#include "CObject.h"

class CTexture;

class CPlayer : 
	public CObject
{
private:
	CTexture* m_pTex = nullptr;

public:
	void update() override;
	void render(HDC _dc) override;

public:
	CPlayer();
	~CPlayer();
};

