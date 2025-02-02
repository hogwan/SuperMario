#pragma once
class CObject
{
private:
	Vec2 m_vPos	= { 0.f,0.f };
	Vec2 m_vScale = { 0.f,0.f };

public:
	inline Vec2 GetPos() { return m_vPos; }
	inline Vec2 GetScale() { return m_vScale; }

	inline void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	inline void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	virtual void update() = 0;
	virtual void render(HDC _dc);

public:
	CObject();
	virtual ~CObject();
};

