#include "pch.h"
#include "CCore.h"
#include "CObject.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"

CObject g_obj;
int CCore::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	// 해상도에 맞게 윈도우 크기 조정

	RECT rt = { 0,0,m_ptResolution.x,m_ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
	SetWindowPos(_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hDC = GetDC(_hWnd);

	g_obj.SetPos(Vec2((int)m_ptResolution.x / 2, m_ptResolution.y / 2));
	g_obj.SetScale(Vec2(100, 100));

	//Manager 초기화
	CTimeMgr::GetInst()->Init();
	CKeyMgr::GetInst()->Init();

	return S_OK;
}


void CCore::progress()
{
	//Manager Update
	CTimeMgr::GetInst()->update();

	update();

	// 그리기
	render();
}

void CCore::update()
{
	Vec2 Pos = g_obj.GetPos();
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		Pos.x -= 200.f * fDT;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		Pos.x += 200.f * fDT;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		Pos.y -= 200.f * fDT;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		Pos.y += 200.f * fDT;
	}

	g_obj.SetPos(Pos);
}

void CCore::render()
{
	Vec2 Pos = g_obj.GetPos();
	Vec2 Scale = g_obj.GetScale();
	Rectangle(m_hDC, static_cast<int>(Pos.x - Scale.x / 2.f),
		static_cast<int>(Pos.y - Scale.y / 2.f),
		static_cast<int>(Pos.x + Scale.x / 2.f),
		static_cast<int>(Pos.y + Scale.y / 2.f));
}

CCore::~CCore()
{
	ReleaseDC(m_hWnd,m_hDC);
}

CCore::CCore()
{

}
