#include <iostream>
#include <climits>
#include "MyString.h"

namespace assignment1
{
	const unsigned int NULL_CHARACTER = 1;
	MyString::MyString(const char* s) // constructor
	{
		if (s == NULL)
		{
			mLength = 0;
			mChars = NULL;
			return;
		}
		unsigned int count = 0;
		const char* p = s;
		while (*p++ != '\0')
		{
			count++;
		}

		mLength = count;
		mChars = new char[mLength + NULL_CHARACTER];
		char* q = mChars;
		p = s;
		while (*p != '\0' && *q != '\0')
		{
			*q++ = *p++;
		}
		*q = '\0';
	}

	MyString::MyString(const MyString& other) // copy constructor
	{
		if (other.GetCString() == NULL)
		{
			mLength = 0;
			mChars = NULL;
			return;
		}
		if (other.GetLength() == 0 && other.GetCString() != NULL)
		{
			mLength = 0;
			*mChars = '\0';
			return;
		}
		mLength = other.mLength;
		mChars = new char[mLength + NULL_CHARACTER];
		char* p = other.mChars;
		char* q = mChars;
		while (*p != '\0' && *q != '\0')
		{
			*q++ = *p++;
		}
		*q = '\0';
	}

	MyString::~MyString() // destructor
	{
		mLength = 0;
		delete[] mChars; // delete char array
		mChars = NULL;
	}

	unsigned int MyString::GetLength() const
	{
		return mLength;
	}

	const char* MyString::GetCString() const
	{
		const char* ret = mChars;
		return ret;
	}

	void MyString::Append(const char* s)
	{
		const char* p = s;
		int count = 0;
		while (*p++ != '\0')
		{
			count++;
		}
		if (count == 0)
		{
			return;
		}
		p = s;
		if (mChars == NULL)
		{
			mLength = count;
			mChars = new char[mLength + NULL_CHARACTER];
			char* q = mChars;
			while (*p != '\0' && *q != '\0')
			{
				*q++ = *p++;
			}
			*q = '\0';
			return;
		}
		char* temp = new char[mLength + NULL_CHARACTER];
		char* q = mChars;
		char* r = temp;
		while (*q != '\0' && *r != '\0')
		{
			*r++ = *q++;
		}
		*r = '\0';
		delete[] mChars;
		mChars = NULL;
		mChars = new char[mLength + count + NULL_CHARACTER]; // similar as reallocation
		q = mChars;
		r = temp;
		while (*r != '\0')
		{
			*q++ = *r++;
		}
		while (*p != '\0')
		{
			*q++ = *p++;
		}
		*q = '\0';
		q = mChars;
		int length = 0;
		while (*q++ != '\0') // because of reallocation, mLength also should be changed
		{
			length++;
		}
		mLength = length;
		delete[] temp; // don't forget delete temp array
		temp = NULL;

	}

	MyString MyString::operator+(const MyString& other) const
	{
		if (other.GetLength() == 0)
		{
			MyString ret = MyString(mChars);
			return ret;
		}
		if (mLength == 0)
		{
			MyString ret = MyString(other.GetCString());
			return ret;
		}
		char* p = other.mChars;
		char* q = mChars;
		unsigned int newLength = other.mLength + mLength + NULL_CHARACTER;
		char* temp = new char[newLength];
		char* r = temp;
		while (*q != '\0')
		{
			*r++ = *q++;
		}
		while (*r != '\0' && *p != '\0')
		{
			*r++ = *p++;
		}
		*r = '\0';
		MyString ret = MyString(temp);
		delete[] temp;
		temp = NULL;
		return ret;
	}

	int MyString::IndexOf(const char* s)
	{
		const char* p = s;
		unsigned int count = 0;
		if (s == NULL)
		{
			return -1;
		}
		while (*p++ != '\0')
		{
			count++;
		}
		if (count > mLength)
		{
			return -1;
		}
		if (count == 0)
		{
			return 0;
		}
		p = s;
		char* q = mChars;
		int start = 0;
		int end = start + count - 1;
		while (*q != '\0') 
		{
			if (q[start] == p[start] && q[end] == p[end]) 
			{
				while (start < end)
				{
					if (q[start] != p[start]) 
					{
						break;
					}
					start++;
				}
				if (start == end) 
				{
					return q - mChars;
				}
				start = 0;
			}
			q++;
		}
		return -1;
	}

	int MyString::LastIndexOf(const char* s)
	{
		const char* p = s;
		unsigned int count = 0;
		int ret = -1;
		if (s == NULL)
		{
			return -1;
		}
		while (*p++ != '\0')
		{
			count++;
		}
		if (count > mLength)
		{
			return -1;
		}
		if (count == 0)
		{
			return mLength;
		}
		p = s;
		char* q = mChars;
		int start = 0;
		int end = start + count - 1;
		while (*q != '\0')
		{
			if (q[start] == p[start] && q[end] == p[end])
			{
				while (start < end)
				{
					if (q[start] != p[start]) 
					{
						break;
					}
					start++;
				}
				if (start == end) 
				{
					ret = q - mChars;
				}
				start = 0;
			}
			q++;
		}
		return ret;
	}

	void MyString::Interleave(const char* s)
	{
		const char* p = s;
		unsigned int count = 0;
		while (*p++ != '\0')
		{
			count++;
		}
		if (count == 0)
		{
			return;
		}
		char* temp = new char[mLength + NULL_CHARACTER];
		char* q = mChars;
		char* r = temp;
		while (*q != '\0')
		{
			*r++ = *q++;
		}
		*r = '\0';
		r = temp;
		int first = mLength;
		int second = count;
		p = s;
		delete[] mChars;
		mChars = NULL;
		mLength = count + mLength;
		mChars = new char[mLength + NULL_CHARACTER];
		q = mChars;
		if (first <= second)
		{
			while (*r != '\0')
			{
				*q++ = *r++;
				*q++ = *p++;
			}
			while (*p != '\0')
			{
				*q++ = *p++;
			}
			*q = '\0';
		}
		else
		{
			while (*p != '\0')
			{
				*q++ = *r++;
				*q++ = *p++;
			}
			while (*r != '\0')
			{
				*q++ = *r++;
			}
			*q = '\0';
		}
		delete[] temp;
		temp = NULL;
	}

	bool MyString::RemoveAt(unsigned int index)
	{
		if (index > mLength - NULL_CHARACTER)
		{
			return false;
		}
		if (mLength == 0)
		{
			return false;
		}
		char* p = mChars;
		unsigned int i = index;
		for (; i < mLength; ++i)
		{
			p[i] = p[i + 1];
		}
		mLength -= 1;
		return true;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		if (totalLength <= mLength)
		{
			return;
		}
		int diff = totalLength - mLength;
		char* temp = new char[mLength + NULL_CHARACTER];
		char* p = mChars;
		char* q = temp;
		while (*p != '\0')
		{
			*q++ = *p++;
		}
		*q = '\0';
		delete[] mChars;
		mChars = NULL;
		mLength = totalLength;
		mChars = new char[totalLength + NULL_CHARACTER];
		p = mChars;
		q = temp;
		for (int i = 0; i < diff; ++i)
		{
			p[i] = ' ';
		}
		p = mChars + diff;
		while (*q != '\0')
		{
			*p++ = *q++;
		}
		*p = '\0';
		delete[] temp;
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		if (totalLength <= mLength)
		{
			return;
		}
		int diff = totalLength - mLength;
		char* temp = new char[mLength + NULL_CHARACTER];
		char* p = mChars;
		char* q = temp;
		while (*p != '\0')
		{
			*q++ = *p++;
		}
		*q = '\0';
		delete[] mChars;
		mChars = NULL;
		mLength = totalLength;
		mChars = new char[totalLength + NULL_CHARACTER];
		p = mChars;
		q = temp;
		for (int i = 0; i < diff; ++i)
		{
			p[i] = c;
		}
		p = mChars + diff;
		while (*q != '\0')
		{
			*p++ = *q++;
		}
		*p = '\0';
		delete[] temp;
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		if (totalLength <= mLength)
		{
			return;
		}
		int diff = totalLength - mLength;
		char* temp = new char[mLength + NULL_CHARACTER];
		char* p = mChars;
		char* q = temp;
		while (*p != '\0')
		{
			*q++ = *p++;
		}
		*q = '\0';
		delete[] mChars;
		mChars = NULL;
		mLength = totalLength;
		mChars = new char[totalLength + NULL_CHARACTER];
		p = mChars;
		q = temp;
		while (*q != '\0')
		{
			*p++ = *q++;
		}
		int i = 0;
		while (i < diff)
		{
			*p++ = ' ';
			i++;
		}
		*p = '\0';
		delete[] temp;
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		if (totalLength <= mLength)
		{
			return;
		}
		int diff = totalLength - mLength;
		char* temp = new char[mLength + NULL_CHARACTER];
		char* p = mChars;
		char* q = temp;
		while (*p != '\0')
		{
			*q++ = *p++;
		}
		*q = '\0';
		delete[] mChars;
		mChars = NULL;
		mLength = totalLength;
		mChars = new char[totalLength + NULL_CHARACTER];
		p = mChars;
		q = temp;
		while (*q != '\0')
		{
			*p++ = *q++;
		}
		int i = 0;
		while (i < diff)
		{
			*p++ = c;
			i++;
		}
		*p = '\0';
		delete[] temp;
	}

	void MyString::Reverse()
	{
		if (mLength == 0)
		{
			return;
		}
		char* p = mChars;
		unsigned int start = 0;
		unsigned int end = mLength - 1;
		while (start < end)
		{
			char temp = p[start];
			p[start] = p[end];
			p[end] = temp;
			start++;
			end--;
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		if (mLength != rhs.GetLength())
		{
			return false;
		}
		char* p = mChars;
		const char* q = rhs.GetCString();
		while (*p != '\0')
		{
			if (*p != *q)
			{
				return false;
			}
			p++;
			q++;
		}
		return true;

	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		if (&rhs == this)
		{
			return *this;
		}
		if (mChars != NULL)
		{
			delete[] mChars;
		}
		mChars = NULL;
		mLength = rhs.GetLength();
		mChars = new char[mLength + NULL_CHARACTER];
		const char* p = rhs.GetCString();
		char* q = mChars;
		while (*p != '\0')
		{
			*q++ = *p++;
		}
		*q = '\0';
		return *this;
	}

	void MyString::ToLower()
	{
		char* p = mChars;
		while (*p != '\0')
		{
			if (*p >= 65 && *p <= 90)
			{
				*p = *p + 32;
			}
			p++;
		}
	}

	void MyString::ToUpper()
	{
		char* p = mChars;
		while (*p != '\0')
		{
			if (*p >= 97 && *p <= 122)
			{
				*p = *p - 32;
			}
			p++;
		}
	}
}

