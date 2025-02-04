#include "pch.h"
#include "CResMgr.h"
#include "CTexture.h"
#include "CPathMgr.h"

CResMgr::CResMgr()
{

}

CResMgr::~CResMgr()
{
	std::map<std::wstring, CTexture*>::iterator iter = m_mapTex.begin();

	for (; iter != m_mapTex.end(); ++iter)
	{
		delete iter->second;
	}
}

CTexture* CResMgr::LoadTexture(const std::wstring& _strKey, const std::wstring& _strRelativePath)
{
	CTexture* pTex = FindTexture(_strKey);
	if (nullptr != pTex)
	{
		return pTex;
	}

	std::wstring strFilePath = CPathMgr::GetInst()->GetContentPath();
	strFilePath += _strRelativePath;

	pTex = new CTexture;
	pTex->Load(strFilePath);

	pTex->SetKey(_strKey);
	pTex->SetRelativePath(_strRelativePath);

	m_mapTex.insert(std::make_pair(_strKey, pTex));

	return pTex;
}

CTexture* CResMgr::FindTexture(const std::wstring& _strKey)
{
	std::map<std::wstring, CTexture*>::iterator iter = m_mapTex.find(_strKey);

	if (iter == m_mapTex.end())
	{
		return nullptr;
	}
	
	return iter->second;
}
