#include "pch.h"
#include "CScene_Start.h"
#include "CPlayer.h"
#include "CTexture.h"
#include "CPathMgr.h"
#include "CMonster.h"
#include "CCollisionMgr.h"
#include "CKeyMgr.h"
#include "CSceneMgr.h"


CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
}

void CScene_Start::update()
{
	CScene::update();

	if (CKeyMgr::GetInst()->GetKeyState(KEY::ENTER) == KEY_STATE::TAP)
	{
		ChangeScene(SCENE_TYPE::TOOL);
	}
}

void CScene_Start::Enter()
{
	// Object 추가
	CObject* pObj = new CPlayer;

	pObj->SetPos(Vec2(640.f, 384.f));
	pObj->SetScale(Vec2(100.f, 100.f));

	AddObject(pObj, GROUP_TYPE::PLAYER);

	pObj = new CMonster;
	pObj->SetPos(Vec2(640.f, 50.f));
	pObj->SetScale(Vec2(80.f, 80.f));
	pObj->SetName(L"Monster");

	AddObject(pObj, GROUP_TYPE::MONSTER);

	// 충돌 지정
	// Player 그룹과 monster 그룹 간의 충돌체크
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::MONSTER, GROUP_TYPE::PROJ_PLAYER);

}

void CScene_Start::Exit()
{
	DeleteAll();

	CCollisionMgr::GetInst()->Reset();
}


