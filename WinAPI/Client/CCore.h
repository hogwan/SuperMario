#pragma once
#include "define.h"

// �̱��� ����
// ��ü�� ������ 1���� ����
// ��𼭵� ���� ���� ����

class CCore
{
public:
	SINGLE(CCore);

private:
	HWND m_hWnd = 0; //���� ������ �ڵ�
	POINT m_ptResolution = { 0,0 }; // ���� ������ �ػ�
	HDC m_hDC = 0; //���� �����쿡 Draw�� DC

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();

	HWND GetMainWnd() { return m_hWnd; }

	void update();
	void render();


};
