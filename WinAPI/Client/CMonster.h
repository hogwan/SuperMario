#pragma once
#include "CObject.h"
class CMonster :
    public CObject
{

public:
    void update() override;
    void render(HDC _dc) override;

    void OnCollisionEnter(CCollider* _pOther) override;
    CMonster* Clone() override { return new CMonster(*this); }


    CMonster();
};

