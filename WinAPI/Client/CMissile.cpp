#include "pch.h"
#include "CMissile.h"
#include "CCollider.h"
#include "CTimeMgr.h"

CMissile::CMissile()
{
	CreateCollider();

	GetCollider()->SetScale(Vec2(10.f, 10.f));

	SetScale(Vec2(15.f, 15.f));
}

CMissile::~CMissile()
{
}

void CMissile::update()
{
	CObject::update();

	Vec2 vPos = GetPos();

	vPos.y -= 300.f * fDT;

	SetPos(vPos);
}

void CMissile::render(HDC _dc)
{
	CObject::render(_dc);

	component_render(_dc);
}

void CMissile::OnCollisionEnter(CCollider* _pOther)
{
	if (_pOther->GetObj()->GetName() == L"Monster")
	{
		DeleteObject(this);
	}
}


