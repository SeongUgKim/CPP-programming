#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <set>

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		size_t index = 0;
		std::map<K, V> m;
		for (K key : keys) 
		{
			if (index >= values.size())
			{
				break;
			}
			m.insert(std::pair<K, V>(key, values[index++]));
		}
		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;
		for (auto iter = m.begin(); iter != m.end(); ++iter)
		{
			v.push_back(iter->first);
		}
		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;
		for (auto iter = m.begin(); iter != m.end(); ++iter)
		{
			v.push_back(iter->second);
		}
		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;
		for (auto iter = v.rbegin(); iter != v.rend(); ++iter)
		{
			rv.push_back(*iter);
		}
		return rv;
	}

	template <typename T>
	std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
	{
		std::vector<T> combined;
		for (size_t i = 0; i < v1.size(); ++i)
		{
			bool bContain = false;
			for (auto iter = combined.begin(); iter != combined.end(); ++iter)
			{
				if (*iter == v1[i])
				{
					bContain = true;
					break;
				}
			}
			if (bContain == false)
			{
				combined.push_back(v1[i]);
			}
		}
		for (size_t i = 0; i < v2.size(); ++i)
		{
			bool bContain = false;
			for (auto iter = combined.begin(); iter != combined.end(); ++iter)
			{
				if (*iter == v2[i])
				{
					bContain = true;
					break;
				}
			}
			if (bContain == false)
			{
				combined.push_back(v2[i]);
			}
		}
		return combined;
	}

	template <typename K, class V>
	std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
	{
		std::map<K, V> combined;
		std::set<K> st;
		for (auto iter = m1.begin(); iter != m1.end(); ++iter)
		{
			st.insert(iter->first);
		}
		for (auto iter = m2.begin(); iter != m2.end(); ++iter)
		{
			st.insert(iter->first);
		}
		for (K key : st)
		{
			auto iter = m1.find(key);
			if (iter != m1.end())
			{
				combined.insert(std::pair<K, V>(key, iter->second));
			}
		}
		for (K key : st)
		{
			auto iter = m2.find(key);
			if (iter != m2.end())
			{
				combined.insert(std::pair<K, V>(key, iter->second));
			}
		}
		return combined;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
	{
		size_t i = 0;
		for (; i < v.size() - 1; ++i)
		{
			os << v[i] << ", ";
		}
		os << v[i];
		return os;
	}

	template <typename K, class V>
	std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
	{
		for (auto iter = m.begin(); iter != m.end(); ++iter)
		{
			os << "{ " << iter->first << ", " << iter->second << " }" << std::endl;
		}
		return os;
	}
}
