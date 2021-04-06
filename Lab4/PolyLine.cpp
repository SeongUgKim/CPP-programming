#include <cstring>
#include <cmath>
#include <cassert>
#include "PolyLine.h"

namespace lab4
{
	const unsigned int ARRAY_SIZE = 10;
	PolyLine::PolyLine()
	{
		mPointList = new const Point* [ARRAY_SIZE];
		memset(mPointList, NULL, sizeof(Point*) * ARRAY_SIZE);
	}

	PolyLine::PolyLine(const PolyLine& other)
	{
		mPointList = new const Point* [ARRAY_SIZE];
		for (int i = 0; i < ARRAY_SIZE; ++i)
		{
			if (other.mPointList[i] == NULL)
			{
				mPointList[i] = NULL;
				continue;
			}
			const Point* p = new Point(other.mPointList[i]->GetX(), other.mPointList[i]->GetY());
			mPointList[i] = p;
		}
	}
	PolyLine& PolyLine::operator=(const PolyLine& rhs)
	{
		if (&rhs == this)
		{
			return *this;
		}
		for (int i = 0; i < ARRAY_SIZE; ++i)
		{
			if (mPointList[i] != NULL)
			{
				assert(mPointList[i] != NULL);
				delete mPointList[i];
				mPointList[i] = NULL;
			}
		}
		for (int i = 0; i < ARRAY_SIZE; ++i)
		{
			if (rhs.mPointList[i] == NULL)
			{
				mPointList[i] = NULL;
				continue;
			}
			const Point* p = new Point(rhs.mPointList[i]->GetX(), rhs.mPointList[i]->GetY());
			mPointList[i] = p;
		}
		return *this;
	}
	PolyLine::~PolyLine()
	{
		for (int i = 0; i < ARRAY_SIZE; ++i)
		{
			delete mPointList[i];
			mPointList[i] = NULL;
		}
		delete[] mPointList;
		mPointList = NULL;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		for (int i = 0; i < ARRAY_SIZE; ++i)
		{
			if (mPointList[i] == NULL)
			{
				const Point* p = new Point(x, y);
				mPointList[i] = p;
				return true;
			}
		}
		return false;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		for (int i = 0; i < ARRAY_SIZE; ++i)
		{
			if (mPointList[i] == NULL)
			{
				mPointList[i] = point;
				return true;
			}
		}
		return false;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= ARRAY_SIZE)
		{
			return false;
		}
		if (mPointList[i] == NULL)
		{
			return false;
		}
		delete mPointList[i];
		for (; i < ARRAY_SIZE - 1; ++i)
		{
			mPointList[i] = mPointList[i + 1];
		}
		if (i == ARRAY_SIZE - 1)
		{
			mPointList[i] = NULL;
		}
		return true;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		int count = 0;
		for (int i = 0; i < ARRAY_SIZE; ++i)
		{
			if (mPointList[i] != NULL)
			{
				count++;
			}
		}
		if (count == 0)
		{
			return false;
		}
		float minX = mPointList[0]->GetX();
		float minY = mPointList[0]->GetY();
		float maxX = mPointList[0]->GetX();
		float maxY = mPointList[0]->GetY();
		for (int i = 1; i < ARRAY_SIZE; ++i)
		{
			if (mPointList[i] == NULL)
			{
				continue;
			}
			float tempX = mPointList[i]->GetX();
			float tempY = mPointList[i]->GetY();
			minX = minX > tempX ? tempX : minX;
			minY = minY > tempY ? tempY : minY;
			maxX = maxX > tempX ? maxX : tempX;
			maxY = maxY > tempY ? maxY : tempY;
		}
		Point min = Point(minX, minY);
		Point max = Point(maxX, maxY);
		outMin->operator=(min);
		outMax->operator=(max);
		return true;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i >= ARRAY_SIZE)
		{
			return NULL;
		}
		return mPointList[i];
	}
}