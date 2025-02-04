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

	CObject* m_pOwner = nullptr; //collider를 소유하고 있는 오브젝트
	Vec2 m_vOffsetPos = {}; //오브젝트로 부터 상대적인 위치
	Vec2 m_vFinalPos = {}; // finalupdate 에서 매 프레임마다 계산

	Vec2 m_vScale = {}; //충돌체의 크기

	UINT m_iID = 0; // 충돌체 고유한 ID값
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
	// 충돌 시점 함수
	void OnCollision(CCollider* _pOther); // 충돌 중인 경우 호출되는 함수
	void OnCollisionEnter(CCollider* _pOther); //충돌 시작
	void OnCollisionExit(CCollider* _pOther); //충돌 끝

public:
	CCollider();
	CCollider(const CCollider& _origin);
	CCollider& operator=(const CCollider& _origin) = delete;
	~CCollider();

	friend class CObject;
};

