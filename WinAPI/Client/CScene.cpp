#include "pch.h"
#include "CScene.h"
#include "CObject.h"




CScene::CScene()
{
}

CScene::~CScene()
{
	for (UINT i = 0; i < static_cast<UINT>(GROUP_TYPE::END); ++i)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); ++j)
		{
			delete m_arrObj[i][j];
			m_arrObj[i][j] = nullptr;
		}
	}
}

void CScene::AddObject(CObject* _obj, GROUP_TYPE _type)
{
	m_arrObj[static_cast<int>(_type)].push_back(_obj);
}

void CScene::update()
{
	for (UINT i = 0; i < static_cast<UINT>(GROUP_TYPE::END); ++i)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); ++j)
		{
			if (false == m_arrObj[i][j]->IsDead())
			{
				m_arrObj[i][j]->update();
			}
		}
	}
}

void CScene::finalupdate()
{
	for (UINT i = 0; i < static_cast<UINT>(GROUP_TYPE::END); ++i)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); ++j)
		{
			m_arrObj[i][j]->finalupdate();
		}
	}
}

void CScene::render(HDC _dc)
{
	for (UINT i = 0; i < static_cast<UINT>(GROUP_TYPE::END); ++i)
	{
		std::vector<CObject*>::iterator iter = m_arrObj[i].begin();

		for (;iter != m_arrObj[i].end();)
		{
			if (!(*iter)->IsDead())
			{
				(*iter)->render(_dc);
				++iter;
			}
			else
			{
				iter = m_arrObj[i].erase(iter);
			}

		}
	}
}

void CScene::DeleteGroup(GROUP_TYPE _eTarget)
{
	Safe_Delete_Vec<CObject*>(m_arrObj[(UINT)_eTarget]);
}

void CScene::DeleteAll()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		DeleteGroup(GROUP_TYPE(i));
	}
}
