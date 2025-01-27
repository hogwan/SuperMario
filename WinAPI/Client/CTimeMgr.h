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

	double m_dDT = 0.0; // ������ ���� �ð���
	double m_dAcc = 0.0; // ���� �ð�

	UINT m_iCallCount = 0; // �ʴ� ȣ�� ȸ��
	UINT m_iFPS = 0; // �ʴ� ������ ȸ��

	// FPS
	// 1. �����Ӵ� �ð� DeltaTime

};

