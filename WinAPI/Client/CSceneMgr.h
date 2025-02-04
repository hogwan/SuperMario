#pragma once

class CScene;
class CSceneMgr
{
	SINGLE(CSceneMgr);

private:
	CScene* m_arrScene[static_cast<UINT>(SCENE_TYPE::END)];  //¸ðµç ¾À ¸ñ·Ï
	CScene* m_pCurScene; // ÇöÀç ¾À

public:
	void Init();
	void update();
	void render(HDC _dc);

	CScene* GetCurScene() { return m_pCurScene; }
};

