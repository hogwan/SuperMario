#include "pch.h"
#include "CCore.h"
#include "CObject.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"

CCore::CCore()
{

}
CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hDC);
	DeleteDC(m_memDC);
	DeleteObject(m_hBit);
}


CObject g_obj;
int CCore::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	// �ػ󵵿� �°� ������ ũ�� ����

	RECT rt = { 0,0,m_ptResolution.x,m_ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
	SetWindowPos(_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hDC = GetDC(_hWnd);

	//���� ���۸� �뵵�� ��Ʈ�ʰ� DC�� �����.
	m_hBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
	m_memDC = CreateCompatibleDC(m_hDC);

	//DC�� �⺻������ �����Ǿ��� �� ����Ʈ ��Ʈ��(1�ȼ�)�� ������ �ְ�,
	//�ʿ䰡 ������ �ٷ� �����ش�.
	HBITMAP hOldBit = (HBITMAP)SelectObject(m_memDC, m_hBit);
	DeleteObject(hOldBit);

	g_obj.SetPos(Vec2((int)m_ptResolution.x / 2, m_ptResolution.y / 2));
	g_obj.SetScale(Vec2(100, 100));

	//Manager �ʱ�ȭ
	CTimeMgr::GetInst()->Init();
	CKeyMgr::GetInst()->Init();

	return S_OK;
}


void CCore::progress()
{
	//Manager Update
	CTimeMgr::GetInst()->update();

	update();

	// �׸���
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
	// ȭ�� Clear
	Rectangle(m_memDC, -1,-1,m_ptResolution.x+1,m_ptResolution.y+1);

	Vec2 Pos = g_obj.GetPos();
	Vec2 Scale = g_obj.GetScale();
	Rectangle(m_memDC, static_cast<int>(Pos.x - Scale.x / 2.f),
		static_cast<int>(Pos.y - Scale.y / 2.f),
		static_cast<int>(Pos.x + Scale.x / 2.f),
		static_cast<int>(Pos.y + Scale.y / 2.f));

	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y,
		m_memDC, 0, 0, SRCCOPY);
}

