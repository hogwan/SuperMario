#include "pch.h"
#include "CPlayer.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"
#include "CTexture.h"
#include "CPathMgr.h"
#include "CResMgr.h"
#include "CCollider.h"


CPlayer::CPlayer()
{
	m_pTex = CResMgr::GetInst()->LoadTexture(L"PlayerTex", L"texture\\TestTexture.bmp");

	CreateCollider();

	GetCollider()->SetScale(Vec2(50.f, 50.f));
}

CPlayer::~CPlayer()
{

}

void CPlayer::update()
{
	Vec2 vPos = GetPos();

	if (CKeyMgr::GetInst()->GetKeyState(KEY::W) == KEY_STATE::HOLD)
	{
		vPos.y -= 200 * fDT;
	}

	if (CKeyMgr::GetInst()->GetKeyState(KEY::S) == KEY_STATE::HOLD)
	{
		vPos.y += 200 * fDT;
	}

	if (CKeyMgr::GetInst()->GetKeyState(KEY::A) == KEY_STATE::HOLD)
	{
		vPos.x -= 200 * fDT;
	}

	if (CKeyMgr::GetInst()->GetKeyState(KEY::D) == KEY_STATE::HOLD)
	{
		vPos.x += 200 * fDT;
	}

	SetPos(vPos);
}

void CPlayer::render(HDC _dc)
{
	int iWidth = static_cast<int>(m_pTex->Width());
	int iHeight = static_cast<int>(m_pTex->Height());

	Vec2 vPos = GetPos();

	int LTX = static_cast<int>(vPos.x - static_cast<float>(iWidth / 2));
	int LTY = static_cast<int>(vPos.y - static_cast<float>(iHeight / 2));


	//BitBlt(_dc, LTX, LTY, iWidth, iHeight, m_pTex->GetDC(), 0, 0, SRCCOPY);

	TransparentBlt(_dc, LTX, LTY, iWidth, iHeight, m_pTex->GetDC(), 0, 0, iWidth, iHeight, RGB(255,0,255));

	component_render(_dc);
}

