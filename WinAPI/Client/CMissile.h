#pragma once
#include "CObject.h"
class CMissile : public CObject
{
public:
	void update() override;
	void render(HDC _dc) override;

	void OnCollisionEnter(CCollider* _pOther) override;

public:
	CMissile();
	~CMissile();
};

