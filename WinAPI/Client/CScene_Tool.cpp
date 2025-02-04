#include "pch.h"
#include "CScene_Tool.h"
#include "CKeyMgr.h"

CScene_Tool::CScene_Tool()
{
}

CScene_Tool::~CScene_Tool()
{
}


void CScene_Tool::Enter()
{
}

void CScene_Tool::Exit()
{
}

void CScene_Tool::update()
{
	CScene::update();
	if (CKeyMgr::GetInst()->GetKeyState(KEY::ENTER) == KEY_STATE::TAP)
	{
		ChangeScene(SCENE_TYPE::START);
	}
}

