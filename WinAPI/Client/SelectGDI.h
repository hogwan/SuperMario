#pragma once
class SelectGDI
{

private:
	HDC m_hDC = 0;
	HPEN m_hDefaultPen = 0;
	HBRUSH m_hDefaultBrush = 0;

public:
	SelectGDI(HDC _dc, PEN_TYPE _ePenType);
	SelectGDI(HDC _dc, BRUSH_TYPE _eBrushType);
	~SelectGDI();
};

