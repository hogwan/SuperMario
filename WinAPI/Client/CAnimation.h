#pragma once

class CAnimator;
class CTexture;

struct tAnimFrm
{
	Vec2 vLT;
	Vec2 vSlice;
	Vec2 vOffset;
	float fDuration;
};

class CAnimation
{
private:
	std::wstring m_strName;
	CAnimator* m_pAnimator = nullptr;
	CTexture* m_pTex = nullptr; //Animation이 사용하는 텍스쳐
	std::vector<tAnimFrm> m_vecFrm; //모든 프레임 정보
	int m_iCurFrm = 0;
	float m_fAccTime = 0.f;
	bool m_bFinish = false; //재생 끝에 도달여부

public:
	const std::wstring& GetName() { return m_strName; }
	bool IsFinish() { return m_bFinish; }
	void SetFrame(int _frameIdx)
	{
		m_bFinish = false;
		m_iCurFrm = _frameIdx;
		m_fAccTime = 0.f;
	}

	tAnimFrm& GetFrame(int _iIdx) { return m_vecFrm[_iIdx]; }
	UINT GetMaxFrame() { return (UINT)m_vecFrm.size(); }
private:
	void SetName(const std::wstring& _strName) { m_strName = _strName; }

public:
	void update();
	void render(HDC _dc);
	void Create(CTexture* _pTex, Vec2 _vLT, Vec2 _vSliceSize,float _fDuration, Vec2 _vStep, UINT _iFrameCount);

public:
	CAnimation();
	~CAnimation();

	friend class CAnimator;
};

