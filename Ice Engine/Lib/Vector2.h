#pragma once
#include <tuple>
struct Vector2 {
	float x, y;
	Vector2& operator/(const float a)
	{
		x = x / a;
		y = y / a;
		return *this;
	}
	Vector2& operator+=(const Vector2& a)
	{
		x = x + a.x;
		y = y + a.y;
		return *this;
	}
	Vector2& operator*(const float a)
	{
		//x = x * a;
		//y = y * a;
		//return *this;
		Vector2 temp = { x * a , y * a };
		return temp;
	}
	Vector2& operator+(const Vector2& a)
	{
		//x = x + a.x;
	//	y = y + a.y;
		Vector2 temp = { x + a.x , y + a.y };
		return temp;
	}
	Vector2& operator-(const Vector2& a)
	{
		Vector2 temp = { x - a.x , y - a.y };
		return temp;
	}
	Vector2& operator-=(const Vector2& a)
	{
		x = x - a.x;
		y = y - a.y;
		return *this;
	}
	bool operator< (const Vector2& o) const {
		return
			x < o.x;
	}
	/*Vector2& operator=(const sf::Vector2f a)
	{
		x =  a.x;
		y =  a.y;
		return *this;
	}*/
};