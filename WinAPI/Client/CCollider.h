#pragma once

class CObject;

union COLLIDER_ID
{
	struct {
		UINT iLeft_id;
		UINT iRight_id;
	};
	LONGLONG ID;
};

class CCollider
{
private:
	static UINT g_iNextID;

	CObject* m_pOwner = nullptr; //collider�� �����ϰ� �ִ� ������Ʈ
	Vec2 m_vOffsetPos = {}; //������Ʈ�� ���� ������� ��ġ
	Vec2 m_vFinalPos = {}; // finalupdate ���� �� �����Ӹ��� ���

	Vec2 m_vScale = {}; //�浹ü�� ũ��

	UINT m_iID = 0; // �浹ü ������ ID��
	UINT m_iCol = 0;

public:
	void SetOffset(Vec2 _vPos) { m_vOffsetPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	Vec2 GetOffset() { return m_vOffsetPos; }
	Vec2 GetScale() { return m_vScale; }
	Vec2 GetFinalPos() { return m_vFinalPos; }

	CObject* GetObj() { return m_pOwner; }

	UINT GetID() { return m_iID; }

public:
	void finalupdate();
	void render(HDC _dc);

public:
	// �浹 ���� �Լ�
	void OnCollision(CCollider* _pOther); // �浹 ���� ��� ȣ��Ǵ� �Լ�
	void OnCollisionEnter(CCollider* _pOther); //�浹 ����
	void OnCollisionExit(CCollider* _pOther); //�浹 ��

public:
	CCollider();
	CCollider(const CCollider& _origin);
	CCollider& operator=(const CCollider& _origin) = delete;
	~CCollider();

	friend class CObject;
};

