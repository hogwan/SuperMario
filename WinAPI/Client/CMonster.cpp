#include "pch.h"
#include "CMonster.h"
#include "CCollider.h"

CMonster::CMonster()
{
	CreateCollider();

	GetCollider()->SetScale(Vec2(70.f, 70.f));
}

void CMonster::update()
{
}

void CMonster::render(HDC _dc)
{
	CObject::render(_dc);

	component_render(_dc);
}

void CMonster::OnCollisionEnter(CCollider* _pOther)
{
	if (L"Missile" == _pOther->GetObj()->GetName())
	{
		DeleteObject(this);
	}
}


