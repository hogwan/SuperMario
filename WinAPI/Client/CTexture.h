#pragma once
#include "CRes.h"

class CTexture
	: public CRes
{
private:
	HDC m_dc = 0;
	HBITMAP m_hBit = 0;
	BITMAP m_bitInfo = {};

public:
	void Load(const std::wstring& _strFilePath);

	UINT Width() { return m_bitInfo.bmWidth; }
	UINT Height() { return m_bitInfo.bmHeight; }

	HDC GetDC() { return m_dc; }

private:
	CTexture();
	~CTexture();

	friend class CResMgr;
};

