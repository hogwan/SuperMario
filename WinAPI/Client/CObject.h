#pragma once
class CObject
{
private:
	Vec2 m_ptPos = { 0.f,0.f };
	Vec2 m_ptScale = { 0.f,0.f };

public:
	inline Vec2 GetPos() { return m_ptPos; }
	inline Vec2 GetScale() { return m_ptScale; }

	inline void SetPos(Vec2 _vPos) { m_ptPos = _vPos; }
	inline void SetScale(Vec2 _vScale) { m_ptScale = _vScale; }
public:
	CObject();
	~CObject();
};

