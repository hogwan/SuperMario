#pragma once

class CObject;
class CAnimation;
class CTexture;

class CAnimator
{
private:
	std::map<std::wstring, CAnimation*> m_mapAnim; // 모든 애니메이션
	CAnimation* m_pCurAnim = nullptr;  //현재 재생중인 Animation
	CObject* m_pOwner = nullptr;
	bool m_bRepeat = false;            //반복 재생 여부

public:
	CObject* GetObj() { return m_pOwner; }

public:
	void CreateAnimation(const std::wstring& _strName, CTexture* _pTex, Vec2 _vLT,Vec2 _vSliceSize, float _fDuration, Vec2 _vStep, UINT _iFrameCount);
	CAnimation* FindAnimation(const std::wstring& _strName);
	void Play(const std::wstring& _strName, bool _bRepeat);

	void update();
	void render(HDC _dc);

public:
	CAnimator();
	~CAnimator();

	friend class CObject;
};

