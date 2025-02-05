#pragma once

struct Vec2
{
	float x = 0.f;
	float y = 0.f;

public:
	Vec2() {}

	Vec2(float _x, float _y) :x(_x), y(_y) {}
	Vec2(int _x, int _y) :x(static_cast<float>(_x)), y(static_cast<float>(_y)) {};
	Vec2(const POINT& _pt) :x(static_cast<float>(_pt.x)), y(static_cast<float>(_pt.y)) {}

	float Length()
	{
		return static_cast<float>(sqrt(x * x + y * y));
	}

	Vec2& Normalize()
	{
		float fLen = Length();

		assert(fLen != 0.f);

		x /= fLen;
		y /= fLen;

		return *this;
	}

public:
	Vec2& operator = (POINT _pt)
	{
		x = static_cast<float>(_pt.x);
		y = static_cast<float>(_pt.y);
	}

	Vec2 operator + (const Vec2 _vOther)
	{
		return Vec2(x + _vOther.x, y + _vOther.y);
	}

	Vec2 operator - (const Vec2 _vOther)
	{
		return Vec2(x - _vOther.x, y - _vOther.y);
	}

	Vec2 operator * (const Vec2 _vOther)
	{
		return Vec2(x * _vOther.x, y * _vOther.y);
	}

	Vec2 operator* (int _i)
	{
		return Vec2(x * (float)_i, y * (float)_i);
	}

	Vec2 operator / (const Vec2 _vOther)
	{
		assert(0.f == _vOther.x || 0.f == _vOther.y);
		return Vec2(x / _vOther.x, y / _vOther.y);
	}

	void operator +=(const Vec2 _vOther)
	{
		x += _vOther.x;
		y += _vOther.y;
	}
};