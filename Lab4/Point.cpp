#include "Point.h"

namespace lab4
{
	Point::Point(float x, float y)
		: mX(x)
		, mY(y)
	{
	}

	Point::~Point()
	{
	}

	Point::Point(const Point& other)
		: mX(other.mX)
		, mY(other.mY)
	{
	}

	Point& Point::operator=(const Point& rhs)
	{
		mX = rhs.mX;
		mY = rhs.mY;
		return *this;
	}

	Point Point::operator+(const Point& other) const
	{
		float resX = mX + other.mX;
		float resY = mY + other.mY;
		Point result = Point(resX, resY);
		return result;
	}

	Point Point::operator-(const Point& other) const
	{
		float resX = mX - other.mX;
		float resY = mY - other.mY;
		Point result = Point(resX, resY);
		return result;
	}

	float Point::Dot(const Point& other) const
	{
		return mX * other.mX + mY * other.mY;
	}

	Point Point::operator*(float operand) const
	{
		float resX = mX * operand;
		float resY = mY * operand;
		Point result = Point(resX, resY);
		return result;
	}

	Point operator*(float operand, const Point& rhs)
	{
		float resX = operand * rhs.mX;
		float resY = operand * rhs.mY;
		Point result = Point(resX, resY);
		return result;
	}

	float Point::GetX() const
	{
		return mX;
	}

	float Point::GetY() const
	{
		return mY;
	}
}