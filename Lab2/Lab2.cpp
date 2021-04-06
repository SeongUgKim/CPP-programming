#include <iomanip>
#include <limits>
#include "Lab2.h"

using namespace std;
namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		out << setw(12) << "oct" << setw(11) << "dec" << setw(9) << "hex" << endl;
		for (int i = 0; i < 12; ++i)
		{
			out << '-';
		}
		out << ' ';
		for (int i = 0; i < 10; ++i)
		{
			out << '-';
		}
		out << ' ';
		for (int i = 0; i < 8; ++i)
		{
			out << '-';
		}
		out << endl;
		unsigned int number;
		string trash;
		while (true)
		{
			in >> number;
			if (!in.fail())
			{
				out << setw(12) << oct << number;
				out << setw(11) << dec << number;
				out << setw(9) << uppercase << noshowbase << hex << number << endl;
				continue;
			}
			if (in.eof())
			{
				break;
			}
			in.clear();
			in >> trash;
		}
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		float number;
		float max = FLT_MAX * (-1);
		string trash;
		while (true)
		{
			in >> number;
			if (!in.fail())
			{
				for (int i = 0; i < 5; ++i)
				{
					out << ' ';
				}
				out << fixed;
				out << setprecision(3);
				if (number >= 0)
				{
					if (number > max)
					{
						max = number;
					}
					out << setw(15) << showpos << internal << showpoint << number << endl;
					continue;
				}
				if (number < 0)
				{
					if (number > max)
					{
						max = number;
					}
					out << setw(15) << internal << showpoint << number << endl;
					continue;
				}
			}
			if (in.eof())
			{
				break;
			}
			in.clear();
			in >> trash;
		}
		out << "max: ";
		if (max >= 0)
		{
			out << setw(15) << showpos << internal << showpoint << max << endl;
			return;
		}
		if (max < 0)
		{
			out << setw(15) << internal << showpoint << max << endl;
			return;
		}
	}
}