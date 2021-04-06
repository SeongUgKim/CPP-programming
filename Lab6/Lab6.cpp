#include <unordered_map>
#include "Lab6.h"

using namespace std;
namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0;
		}
		int sum = 0;
		for (int n : v)
		{
			sum += n;
		}
		return sum;
	}

	int Min(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return INT_MAX;
		}
		int minimum = INT_MAX;
		for (int n : v)
		{
			minimum = n < minimum ? n : minimum;
		}
		return minimum;
	}

	int Max(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return INT_MIN;
		}
		int maximum = INT_MIN;
		for (int n : v)
		{
			maximum = n > maximum ? n : maximum;
		}
		return maximum;
	}

	float Average(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0.0f;
		}
		int sum = 0;
		for (int n : v)
		{
			sum += n;
		}
		float avg = static_cast<float>(sum) / v.size();
		return avg;
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0;
		}
		unordered_map<int, int> map;
		for (int n : v)
		{
			map[n]++;
		}
		int maximum = 0;
		int result = INT_MIN;
		for (int n : v)
		{
			if (map[n] > maximum)
			{
				maximum = map[n];
				result = n;
			}
		}
		return result;
	}

	void SortDescending(std::vector<int>& v)
	{
		for (int i = 0; i < static_cast<int>(v.size()) - 1; ++i)
		{
			int max = i;
			for (int j = i + 1; j < static_cast<int>(v.size()); ++j)
			{
				if (v[j] > v[max])
				{
					max = j;
				}
			}
			int temp = v[max];
			v[max] = v[i];
			v[i] = temp;
		}
	}

}