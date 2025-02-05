#include "pch.h"
#include "CAnimation.h"
#include "CAnimator.h"
#include "CTexture.h"
#include "CObject.h"
#include "CTimeMgr.h"

CAnimation::CAnimation()
{
}

CAnimation::~CAnimation()
{
}


void CAnimation::update()
{
	if (m_bFinish)
		return;

	m_fAccTime += fDT;

	if (m_fAccTime > m_vecFrm[m_iCurFrm].fDuration)
	{
		++m_iCurFrm;
		if (m_vecFrm.size() <= m_iCurFrm)
		{
			m_iCurFrm = -1;
			m_bFinish = true;
			m_fAccTime = 0.f;
			return;
		}

		m_fAccTime = m_fAccTime - m_vecFrm[m_iCurFrm].fDuration;
	}
}

void CAnimation::render(HDC _dc)
{
	if (m_bFinish)
		return;

	CObject* pObj = m_pAnimator->GetObj();
	
	Vec2 vPos = pObj->GetPos();
	Vec2 vScale = m_vecFrm[m_iCurFrm].vSlice;
	Vec2 vLT = m_vecFrm[m_iCurFrm].vLT;
	vPos += m_vecFrm[m_iCurFrm].vOffset; //Object Position 에 Offset 만큼 추가

	TransparentBlt(_dc
		, static_cast<int>(vPos.x - vScale.x / 2.f)
		, static_cast<int>(vPos.y - vScale.y / 2.f)
		, static_cast<int>(vScale.x)
		, static_cast<int>(vScale.y)
		, m_pTex->GetDC()
		, static_cast<int>(vLT.x)
		, static_cast<int>(vLT.y)
		, static_cast<int>(vScale.x)
		, static_cast<int>(vScale.y)
		, RGB(255, 0, 255));
}

void CAnimation::Create(CTexture* _pTex, Vec2 _vLT, Vec2 _vSliceSize, float _fDuration, Vec2 _vStep, UINT _iFrameCount)
{
	m_pTex = _pTex;

	tAnimFrm frm = {};

	for (UINT i = 0; i < _iFrameCount; ++i)
	{
		frm.fDuration = _fDuration;
		frm.vSlice = _vSliceSize;
		frm.vLT = _vLT + _vStep * i;

		m_vecFrm.push_back(frm);
	}
}
