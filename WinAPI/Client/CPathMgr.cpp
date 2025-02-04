#include "pch.h"
#include "CPathMgr.h"
#include "CCore.h"

CPathMgr::CPathMgr()
{

}

CPathMgr::~CPathMgr()
{

}

void CPathMgr::Init()
{
	GetCurrentDirectory(255, m_szContentPath);

	int iLen = static_cast<int>(wcslen(m_szContentPath));

	// 상위 폴더로
	for (int i = iLen - 1; i >= 0; i--)
	{
		if (m_szContentPath[i] == '\\')
		{
			m_szContentPath[i] = '\0';
			break;
		}
	}

	wcscat_s(m_szContentPath, 255, L"\\bin\\content\\");
	

	int a = 0;
	// +bin\\content\\
	
	//SetWindowText(CCore::GetInst()->GetMainWnd(), m_szContentPath);
}
