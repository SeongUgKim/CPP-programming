#include <cassert>
#include "SmartStack.h"
#include "SmartQueue.h"
#include "QueueStack.h"
using namespace assignment3;

int main()
{
	const double EPSILON = 0.0009765625;
	SmartStack<double> ss;

	ss.Push(3.4);
	ss.Push(1.2);
	ss.Push(4.6);
	ss.Push(3.32);
	ss.Push(10.2);
	ss.Push(1.1);
	ss.Push(-5.9);
	ss.Push(1.1);
	ss.Push(-12.4);
	ss.Push(9.2);
	SmartStack<double> ss1;
	ss1.Push(2.3);
	ss1 = ss;
	assert(ss.GetCount() == 10U);
	assert(ss.Peek() == 9.2);
	assert(ss.GetMax() == 10.2);
	assert(ss.GetMin() == -12.4);
	assert(std::abs(ss.GetSum() - 15.82) <= EPSILON);
	assert(std::abs(ss.GetAverage() - 1.582) <= EPSILON);
	assert(std::abs(ss.GetVariance() - 39.983) <= EPSILON);
	assert(std::abs(ss.GetStandardDeviation() - 6.323) <= EPSILON);
	assert(ss.Peek() == 9.2);
	assert(ss1.GetCount() == 10U);
	assert(ss1.Peek() == 9.2);
	assert(ss1.GetMax() == 10.2);
	assert(ss1.GetMin() == -12.4);
	assert(std::abs(ss1.GetSum() - 15.82) <= EPSILON);
	assert(std::abs(ss1.GetAverage() - 1.582) <= EPSILON);
	assert(std::abs(ss1.GetVariance() - 39.983) <= EPSILON);
	assert(std::abs(ss1.GetStandardDeviation() - 6.323) <= EPSILON);
	assert(ss1.Peek() == 9.2);

	double popped1 = ss.Pop();
	double popped2 = ss.Pop();

	assert(popped1 == 9.2);
	assert(popped2 == -12.4);


	SmartQueue<float> sq;
	sq.Enqueue(-12.4f);
	sq.Enqueue(10.2f);
	sq.Enqueue(4.6555f);
	sq.Enqueue(3.3299f);
	sq.Enqueue(1.2f);
	sq.Enqueue(1.1f);
	sq.Enqueue(-5.9f);
	sq.Enqueue(1.1f);
	sq.Enqueue(3.4999f);
	sq.Enqueue(9.2f);
	SmartQueue<float> sq1;
	sq1.Enqueue(2.4f);
	sq1 = sq;
	assert(sq.GetCount() == 10U);
	assert(sq.Peek() == -12.4f);
	assert(sq.GetMax() == 10.2f);
	assert(sq.GetMin() == -12.4f);
	assert(std::abs(sq.GetSum() - 15.985301f) <= EPSILON);
	assert(std::abs(sq.GetAverage() - 1.599) <= EPSILON);
	assert(std::abs(sq.GetVariance() - 40.057) <= EPSILON);
	assert(std::abs(sq.GetStandardDeviation() - 6.329) <= EPSILON);
	assert(sq.Peek() == -12.4f);
	assert(sq1.GetCount() == 10U);
	assert(sq1.Peek() == -12.4f);
	assert(sq1.GetMax() == 10.2f);
	assert(sq1.GetMin() == -12.4f);
	assert(std::abs(sq1.GetSum() - 15.985301f) <= EPSILON);
	assert(std::abs(sq1.GetAverage() - 1.599) <= EPSILON);
	assert(std::abs(sq1.GetVariance() - 40.057) <= EPSILON);
	assert(std::abs(sq1.GetStandardDeviation() - 6.329) <= EPSILON);
	assert(sq1.Peek() == -12.4f);

	float dequeued1 = sq.Dequeue();
	float dequeued2 = sq.Dequeue();

	assert(dequeued1 == -12.4f);
	assert(dequeued2 == 10.2f);
	assert(sq.GetCount() == 8U);
	assert(sq.Peek() == 4.6555f);
	assert(sq.GetMax() == 9.2f);
	assert(sq.GetMin() == -5.9f);
	/*assert(std::abs(sq.GetSum() - 19.1853008f) <= EPSILON);
	assert(std::abs(sq.GetAverage() - 2.398) <= EPSILON);
	assert(std::abs(sq.GetVariance() - 17.714) <= EPSILON);
	assert(std::abs(sq.GetStandardDeviation() - 4.209) <= EPSILON);*/

	QueueStack<int> qs(3);
	qs.Enqueue(1); // [ [ 1 ] ]
	qs.Enqueue(2); // [ [ 1, 2 ] ]
	qs.Enqueue(3); // [ [ 1, 2, 3 ] ]
	qs.Enqueue(4); // [ [ 1, 2, 3 ], [ 4 ] ]
	qs.Enqueue(5); // [ [ 1, 2, 3 ], [ 4, 5 ] ]
	qs.Enqueue(6);
	QueueStack<int> qs1 = qs;
	assert(qs.GetCount() == 6U);
	assert(qs.GetStackCount() == 2U);
	assert(qs.Peek() == 3);
	assert(qs.GetMax() == 6);
	assert(qs.GetMin() == 1);
	assert(std::abs(qs.GetSum() - 21) <= EPSILON);
	assert(std::abs(qs.GetAverage() - 3.5) <= EPSILON);
	assert(qs1.GetCount() == 6U);
	assert(qs1.GetStackCount() == 2U);
	assert(qs1.Peek() == 3);
	assert(qs1.GetMax() == 6);
	assert(qs1.GetMin() == 1);
	assert(std::abs(qs1.GetSum() - 21) <= EPSILON);
	assert(std::abs(qs1.GetAverage() - 3.5) <= EPSILON);
	qs.Dequeue();
	qs.Dequeue();
	assert(qs.GetCount() == 4U);
	assert(qs.GetStackCount() == 2U);
	assert(qs.Peek() == 1);
	assert(qs.GetMax() == 6);
	assert(qs.GetMin() == 1);
	assert(std::abs(qs.GetSum() - 16) <= EPSILON);
	assert(std::abs(qs.GetAverage() - 4.0) <= EPSILON);
	qs.Enqueue(7);
	qs.Enqueue(8);
	qs.Enqueue(-1);
	assert(qs.GetCount() == 7U);
	assert(qs.GetStackCount() == 3U);
	assert(qs.Peek() == 1);
	assert(qs.GetMax() == 8);
	assert(qs.GetMin() == -1);
	assert(std::abs(qs.GetSum() - 30) <= EPSILON);
	assert(std::abs(qs.GetAverage() - 4.286) <= EPSILON);

	/*const double EPSILON = 0.0009765625;

	SmartStack<float> ss;

	ss.Push(3.4999f);
	ss.Push(1.2f);
	ss.Push(4.6555f);
	ss.Push(3.3299f);
	ss.Push(10.2f);
	ss.Push(1.1f);
	ss.Push(-5.9f);
	ss.Push(1.1f);
	ss.Push(-12.4f);
	ss.Push(9.2f);

	assert(ss.GetCount() == 10U);
	assert(ss.Peek() == 9.2f);
	assert(ss.GetMax() == 10.2f);
	assert(ss.GetMin() == -12.4f);
	assert(std::abs(ss.GetSum() - 15.985301f) <= EPSILON);
	assert(std::abs(ss.GetAverage() - 1.599) <= EPSILON);
	assert(std::abs(ss.GetVariance() - 40.057) <= EPSILON);
	assert(std::abs(ss.GetStandardDeviation() - 6.329) <= EPSILON);
	assert(ss.Peek() == 9.2f);

	float popped1 = ss.Pop();
	float popped2 = ss.Pop();

	assert(popped1 == 9.2f);
	assert(popped2 == -12.4f);
	assert(ss.GetCount() == 8U);
	assert(ss.Peek() == 1.1f);
	assert(ss.GetMax() == 10.2f);
	assert(ss.GetMin() == -5.9f);
	assert(std::abs(ss.GetSum() - 19.1853008f) <= EPSILON);
	assert(std::abs(ss.GetAverage() - 2.398) <= EPSILON);
	assert(std::abs(ss.GetVariance() - 17.714) <= EPSILON);
	assert(std::abs(ss.GetStandardDeviation() - 4.209) <= EPSILON);
	*/
	return 0;
}