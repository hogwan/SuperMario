#pragma once
class CTimeMgr
{
	SINGLE(CTimeMgr);

public:
	void Init();
	void update();

	double GetDT() { return m_dDT; }
	float GetfDT() { return static_cast<float>(m_dDT); }

private:
	LARGE_INTEGER m_llPrevCount = {};
	LARGE_INTEGER m_llCurCount = {};
	LARGE_INTEGER m_llFrequency = {};

	double m_dDT = 0.0; // 프레임 간의 시간값
	double m_dAcc = 0.0; // 축적 시간

	UINT m_iCallCount = 0; // 초당 호출 회수
	UINT m_iFPS = 0; // 초당 프레임 회수

	// FPS
	// 1. 프레임당 시간 DeltaTime

};

