#pragma once
#include "define.h"

// 싱글톤 패턴
// 객체의 생성을 1개로 제한
// 어디서든 쉽게 접근 가능

class CCore
{
public:
	SINGLE(CCore);

private:
	HWND m_hWnd = 0; //메인 윈도우 핸들
	POINT m_ptResolution = { 0,0 }; // 메인 윈도우 해상도
	HDC m_hDC = 0; //메인 윈도우에 Draw할 DC

	HBITMAP m_hBit = 0;
	HDC m_memDC = 0;

	// 자주 사용하는 GDI Object
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
