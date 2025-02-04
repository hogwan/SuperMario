#pragma once
#include <map>

class CObject;
class CScene
{
private:
	//������Ʈ�� ���� �� ������ ���͸� �׷� ������ŭ ����
	std::vector<CObject*> m_arrObj[static_cast<UINT>(GROUP_TYPE::END)];
	std::wstring m_strName; //Scene �̸�
public:
	void SetName(const std::wstring& _strName) { m_strName = _strName; }
	const std::wstring& GetName() { return m_strName; }

	virtual void Enter() = 0; //�ش� Scene�� ���� �� ȣ��
	virtual void Exit() = 0; //�ش� Scene�� Ż�� �� ȣ��

	void AddObject(CObject* _obj, GROUP_TYPE _type);

	void update();
	void finalupdate();
	void render(HDC _dc);

	const std::vector<CObject*>& GetGroupObject(GROUP_TYPE _eType)
	{
		return m_arrObj[(UINT)_eType];
	}

public:
	CScene();
	virtual ~CScene();
};

