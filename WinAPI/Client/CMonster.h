#pragma once
#include "CObject.h"
class CMonster :
    public CObject
{

public:
    void update() override;
    void render(HDC _dc) override;

    CMonster();
};

