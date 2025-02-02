#include "pch.h"
#include "CObject.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"


CObject::CObject()
{
}

CObject::~CObject()
{
}
void CObject::update()
{
	
}

void CObject::render(HDC _dc)
{
	Rectangle(_dc, static_cast<int>(m_vPos.x - m_vScale.x / 2.f)
		, static_cast<int>(m_vPos.y - m_vScale.y / 2.f)
		, static_cast<int>(m_vPos.x + m_vScale.x / 2.f)
		, static_cast<int>(m_vPos.y + m_vScale.y / 2.f));
}

