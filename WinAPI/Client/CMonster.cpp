#include "pch.h"
#include "CMonster.h"
#include "CCollider.h"

void CMonster::update()
{
}

void CMonster::render(HDC _dc)
{
	CObject::render(_dc);

	component_render(_dc);
}

CMonster::CMonster()
{
	CreateCollider();

	GetCollider()->SetScale(Vec2(70.f,70.f));
}
