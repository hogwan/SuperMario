#pragma once

#include "CCamera.h"

class CCollider;
class CAnimator;

class CObject
{
private:
	std::wstring	m_strName;

	Vec2			m_vPos			= { 0.f,0.f };
	Vec2			m_vScale		= { 0.f,0.f };

	//component
	CCollider*		m_pCollider		= nullptr;
	CAnimator*		m_pAnimator		= nullptr;

	bool m_bAlive = true;

public:
	inline Vec2 GetPos() { return m_vPos; }
	inline Vec2 GetScale() { return m_vScale; }

	inline void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	inline void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	void SetName(const std::wstring _strName) { m_strName = _strName; }
	const std::wstring& GetName() { return m_strName; }

	void CreateCollider();
	void CreateAnimator();

	CAnimator* GetAnimator() { return m_pAnimator; }
	CCollider* GetCollider() { return m_pCollider; }

	bool IsDead() { return !m_bAlive; }

private:
	void SetDead() { m_bAlive = false; }

public:
	virtual CObject* Clone() = 0;

	virtual void update() = 0;
	virtual void finalupdate() final;
	virtual void render(HDC _dc);

	virtual void OnCollision(CCollider* _pOther) {}
	virtual void OnCollisionEnter(CCollider* _pOther) {}
	virtual void OnCollisionExit(CCollider* _pOther) {}

	// 컴포넌트 (충돌체, ...)
	void component_render(HDC _dc);

public:
	CObject();
	CObject(const CObject& _origin);
	virtual ~CObject();

	friend class CEventMgr;
};

