#include "pch.h"
#include "CScene_Start.h"
#include "CPlayer.h"
#include "CTexture.h"
#include "CPathMgr.h"
#include "CMonster.h"
#include "CCollisionMgr.h"


CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
}

void CScene_Start::Enter()
{
	// Object �߰�
	CObject* pObj = new CPlayer;

	pObj->SetPos(Vec2(640.f, 384.f));
	pObj->SetScale(Vec2(100.f, 100.f));

	AddObject(pObj, GROUP_TYPE::PLAYER);

	pObj = new CMonster;
	pObj->SetPos(Vec2(640.f, 50.f));
	pObj->SetScale(Vec2(80.f, 80.f));

	AddObject(pObj, GROUP_TYPE::MONSTER);

	// �浹 ����
	// Player �׷�� monster �׷� ���� �浹üũ
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);

}

void CScene_Start::Exit()
{
	CCollisionMgr::GetInst()->Reset();
}
