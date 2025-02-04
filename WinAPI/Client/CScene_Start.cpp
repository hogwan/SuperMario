#include "pch.h"
#include "CScene_Start.h"
#include "CPlayer.h"
#include "CTexture.h"
#include "CPathMgr.h"


CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
}

void CScene_Start::Enter()
{
	

	// Object Ãß°¡
	CObject* pObj = new CPlayer;

	pObj->SetPos(Vec2(640.f, 384.f));
	pObj->SetScale(Vec2(100.f, 100.f));

	AddObject(pObj, GROUP_TYPE::DEFAULT);

}

void CScene_Start::Exit()
{
}
