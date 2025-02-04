#pragma once
#include <map>

class CObject;
class CScene
{
private:
	//오브젝트를 저장 및 관리할 벡터를 그룹 개수만큼 선언
	std::vector<CObject*> m_arrObj[static_cast<UINT>(GROUP_TYPE::END)];
	std::wstring m_strName; //Scene 이름
public:
	void SetName(const std::wstring& _strName) { m_strName = _strName; }
	const std::wstring& GetName() { return m_strName; }

	virtual void update();
	virtual void finalupdate();
	virtual void render(HDC _dc);

	virtual void Enter() = 0; //해당 Scene에 진입 시 호출
	virtual void Exit() = 0; //해당 Scene을 탈출 시 호출

public:
	void AddObject(CObject* _obj, GROUP_TYPE _type);
	const std::vector<CObject*>& GetGroupObject(GROUP_TYPE _eType)
	{
		return m_arrObj[(UINT)_eType];
	}
	void DeleteGroup(GROUP_TYPE _eTarget);
	void DeleteAll();

public:
	CScene();
	virtual ~CScene();
};

