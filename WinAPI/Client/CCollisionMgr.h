#pragma once

class CCollider;
class CCollisionMgr
{
	SINGLE(CCollisionMgr);
private:
	std::map<ULONGLONG, bool> m_mapColInfo;//�浹ü ���� ���� ������ �浹 ����
	UINT m_arrCheck[(UINT)GROUP_TYPE::END] = {}; // �׷찣�� �浹 ��Ʈ����

public:
	void Init();
	void update();
	void CheckGroup(GROUP_TYPE _eLeft, GROUP_TYPE _eRight);
	void Reset();

private:
	void CollisionUpdateGroup(GROUP_TYPE _eLeft, GROUP_TYPE _eRight);
	bool IsCollision(CCollider* _pLeftCol, CCollider* _pRightCol);
};

