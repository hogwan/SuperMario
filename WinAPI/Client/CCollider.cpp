#include "pch.h"
#include "CCollider.h"
#include "CObject.h"
#include "SelectGDI.h"

void CCollider::finalupdate()
{
	Vec2 vObjectPos = m_pOwner->GetPos();
	m_vFinalPos = vObjectPos + m_vOffsetPos;

}

void CCollider::render(HDC _dc)
{
	SelectGDI p(_dc, PEN_TYPE::GREEN);
	SelectGDI b(_dc, BRUSH_TYPE::HOLLOW);

	Rectangle(_dc
		, static_cast<int>(m_vFinalPos.x - m_vScale.x / 2.f)
		, static_cast<int>(m_vFinalPos.y - m_vScale.y / 2.f)
		, static_cast<int>(m_vFinalPos.x + m_vScale.x / 2.f)
		, static_cast<int>(m_vFinalPos.y + m_vScale.y / 2.f));

}
