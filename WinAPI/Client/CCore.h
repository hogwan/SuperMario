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

	HBITMAP m_hBit = 0;
	HDC m_memDC = 0;

	// ���� ����ϴ� GDI Object
	HBRUSH m_arrBrush[(UINT)BRUSH_TYPE::END] = {};
	HPEN m_arrPen[(UINT)PEN_TYPE::END] = {};

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();

	HWND GetMainWnd() { return m_hWnd; }
	HDC GetMainDC() { return m_hDC; }
	HBRUSH GetBrush(BRUSH_TYPE _eType) { return m_arrBrush[(UINT)_eType]; }
	HPEN GetPen(PEN_TYPE _eType) { return m_arrPen[(UINT)_eType]; }

	void CreateBrushPen();

};
