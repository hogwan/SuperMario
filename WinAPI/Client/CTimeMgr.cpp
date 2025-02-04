#include "pch.h"
#include "CTimeMgr.h"
#include "CCore.h"
#include <iostream>

CTimeMgr::CTimeMgr()
{

}

CTimeMgr::~CTimeMgr()
{

}

void CTimeMgr::Init()
{
	QueryPerformanceCounter(&m_llPrevCount);
	QueryPerformanceFrequency(&m_llFrequency);
}

void CTimeMgr::update()
{
	QueryPerformanceCounter(&m_llCurCount);

	// ���� �������� ī���ð�, ���� ������ ī���� ���� ���̸� ���Ѵ�
	m_dDT = static_cast<double>((m_llCurCount.QuadPart - m_llPrevCount.QuadPart))
		/static_cast<double>(m_llFrequency.QuadPart);

	m_llPrevCount = m_llCurCount;
}

void CTimeMgr::render()
{
	m_dAcc += m_dDT;
	++m_iCallCount;
	if (m_dAcc >= 1.0)
	{
		m_iFPS = m_iCallCount;
		m_iCallCount = 0;
		m_dAcc = 0.0;

		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS: %d, DT : %f", m_iFPS, m_dDT);
		SetWindowText(CCore::GetInst()->GetMainWnd(), szBuffer);
	}
}
