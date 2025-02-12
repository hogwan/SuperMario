#include "pch.h"
#include "CCollider.h"
#include "CObject.h"
#include "SelectGDI.h"

UINT CCollider::g_iNextID = 0;

CCollider::CCollider()
	:m_iID(g_iNextID++)
{
}

CCollider::CCollider(const CCollider& _origin)
	:m_pOwner(nullptr)
	, m_vOffsetPos(_origin.m_vOffsetPos)
	, m_vScale(_origin.m_vScale)
	, m_iID(g_iNextID++)
{

}

CCollider::~CCollider()
{
}

void CCollider::finalupdate()
{
	Vec2 vObjectPos = m_pOwner->GetPos();
	m_vFinalPos = vObjectPos + m_vOffsetPos;

	assert(0 <= m_iCol);
}

void CCollider::render(HDC _dc)
{
	PEN_TYPE ePen = PEN_TYPE::GREEN;

	if (m_iCol)
	{
		ePen = PEN_TYPE::RED;
	}

	SelectGDI p(_dc, ePen);
	SelectGDI b(_dc, BRUSH_TYPE::HOLLOW);

	Vec2 vPos = CCamera::GetInst()->GetRenderPos(m_vFinalPos);
	Rectangle(_dc
		, static_cast<int>(vPos.x - m_vScale.x / 2.f)
		, static_cast<int>(vPos.y - m_vScale.y / 2.f)
		, static_cast<int>(vPos.x + m_vScale.x / 2.f)
		, static_cast<int>(vPos.y + m_vScale.y / 2.f));

}

void CCollider::OnCollision(CCollider* _pOther)
{
	m_pOwner->OnCollision(_pOther);
}

void CCollider::OnCollisionEnter(CCollider* _pOther)
{
	++m_iCol;
	m_pOwner->OnCollisionEnter(_pOther);
}

void CCollider::OnCollisionExit(CCollider* _pOther)
{
	--m_iCol;
	m_pOwner->OnCollisionExit(_pOther);
}


