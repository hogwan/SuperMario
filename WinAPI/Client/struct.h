#pragma once

struct Vec2
{
	float x = 0.f;
	float y = 0.f;

public:
	Vec2() {}

	Vec2(float _x, float _y) :x(_x), y(_y) {}
	Vec2(int _x, int _y) :x(static_cast<float>(_x)), y(static_cast<float>(_y)) {};
};