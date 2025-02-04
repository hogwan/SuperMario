#pragma once

class CCollider;
class CCollisionMgr
{
	SINGLE(CCollisionMgr);
private:
	std::map<ULONGLONG, bool> m_mapColInfo;//충돌체 간의 이전 프레임 충돌 정보
	UINT m_arrCheck[(UINT)GROUP_TYPE::END] = {}; // 그룹간의 충돌 매트릭스

public:
	void Init();
	void update();
	void CheckGroup(GROUP_TYPE _eLeft, GROUP_TYPE _eRight);
	void Reset();

private:
	void CollisionUpdateGroup(GROUP_TYPE _eLeft, GROUP_TYPE _eRight);
	bool IsCollision(CCollider* _pLeftCol, CCollider* _pRightCol);
};

