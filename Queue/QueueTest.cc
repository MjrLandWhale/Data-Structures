#include <iostream>
#include "Queue.cc"
using namespace std;

/*****************************************
 * YOU MAY NOT CHANGE ANYTHING BELOW THIS!
 *****************************************/
int main()
{
	Queue<int> q1;

	cout << "*declare queue q1\nq1=" << q1 << endl; // queue initially set to 0
	cout << "q1.Size()=" << q1.Size() << endl;
	cout << "q1.IsEmpty()=" << ((q1.IsEmpty()) ? "T" : "F") << endl;
	cout << "q1.IsFull()=" << ((q1.IsFull()) ? "T" : "F") << endl;
	cout << "q1.Peek()=" << q1.Peek() << endl;
	cout << endl;

	for (int i=0; i<1000; i++) // enqueue 1000 times with i+100
		q1.Enqueue(i+100);
	cout << "*Enqueue(i+100) 1000 times\nq1=" << q1 << endl;
	cout << "q1.Size()=" << q1.Size() << endl;
	cout << "q1.IsEmpty()=" << ((q1.IsEmpty()) ? "T" : "F") << endl;
	cout << "q1.IsFull()=" << ((q1.IsFull()) ? "T" : "F") << endl;
	cout << "q1.Peek()=" << q1.Peek() << endl;
	cout << endl;

	for (int i=0; i<10; i++) // dequeue 10 times
		q1.Dequeue();
	cout << "*dequeue 10 times\nq1=" << q1 << endl;
	cout << "q1.Size()=" << q1.Size() << endl;
	cout << "q1.IsEmpty()=" << ((q1.IsEmpty()) ? "T" : "F") << endl;
	cout << "q1.IsFull()=" << ((q1.IsFull()) ? "T" : "F") << endl;
	cout << "q1.Peek()=" << q1.Peek() << endl;
	cout << endl;

	for (int i=0; i<1000; i++) // dequeue 1000 times
		q1.Dequeue();
	cout << "*dequeue 1000 times\nq1=" << q1 << endl;
	cout << "q1.Size()=" << q1.Size() << endl;
	cout << "q1.IsEmpty()=" << ((q1.IsEmpty()) ? "T" : "F") << endl;
	cout << "q1.IsFull()=" << ((q1.IsFull()) ? "T" : "F") << endl;
	cout << "q1.Peek()=" << q1.Peek() << endl;
	cout << endl;

	for (int i=0; i<10; i++) // enqueue 10 times with i*i
		q1.Enqueue(i*i);
	cout << "*enqueue 10 times with i*i\nq1=" << q1 << endl;
	cout << "q1.Size()=" << q1.Size() << endl;
	cout << "q1.IsEmpty()=" << ((q1.IsEmpty()) ? "T" : "F") << endl;
	cout << "q1.IsFull()=" << ((q1.IsFull()) ? "T" : "F") << endl;
	cout << "q1.Peek()=" << q1.Peek() << endl;
	cout << endl;

	Queue<int> q2(q1); // q2 declared as a copy of q1
	cout << "*declare q2 as a copy of q1 (queue q2(q1))\nq2=" << q2 << endl;
	cout << "q2.Size()=" << q2.Size() << endl;
	cout << "q2.IsEmpty()=" << ((q2.IsEmpty()) ? "T" : "F") << endl;
	cout << "q2.IsFull()=" << ((q2.IsFull()) ? "T" : "F") << endl;
	cout << "q2.Peek()=" << q2.Peek() << endl;
	cout << endl;

	Queue<int> q3;
	q3 = q3 + q2; cout << "*declare q3 as a copy of q2 (queue q3 = q2)\nq3=" << q3 << endl; // copy constructor (=)
	cout << "q3.Size()=" << q3.Size() << endl;
	cout << "q3.IsEmpty()=" << ((q3.IsEmpty()) ? "T" : "F") << endl;
	cout << "q3.IsFull()=" << ((q3.IsFull()) ? "T" : "F") << endl;
	cout << "q3.Peek()=" << q3.Peek() << endl;
	cout << endl;

	q2 = Queue<int>(); cout << "*reset q2 to 0\nq2=" << q2 << endl; // reset queue to 0
	cout << "q2.Size()=" << q2.Size() << endl;
	cout << "q2.IsEmpty()=" << ((q2.IsEmpty()) ? "T" : "F") << endl;
	cout << "q2.IsFull()=" << ((q2.IsFull()) ? "T" : "F") << endl;
	cout << "q2.Peek()=" << q2.Peek() << endl;
	cout << endl;

	cout << "q1=" << q1 << "\nq2=" << q2 << "\nq3=" << q3 << endl;
	cout << "q1 == q2; =" << ((q1 == q2) ? "T" : "F") << endl; // test ==
	cout << "q1 == q3; =" << ((q1 == q3) ? "T" : "F") << endl;
	cout << "q1 != q3; =" << ((q1 != q3) ? "T" : "F") << endl;
	cout << endl;

	q1 = q1 + q2; cout << "*q1 = q1 + q2\nq1=" << q1 << endl; // test +
	cout << "q1.Size()=" << q1.Size() << endl;
	cout << "q1.IsEmpty()=" << ((q1.IsEmpty()) ? "T" : "F") << endl;
	cout << "q1.IsFull()=" << ((q1.IsFull()) ? "T" : "F") << endl;
	cout << "q1.Peek()=" << q1.Peek() << endl;
	cout << endl;

	for (int i=0; i<5; i++)
		q1.Dequeue();
	cout << "*dequeue q1 5 times\n";
	cout << "q1=" << q1 << "\nq2=" << q2 << "\nq3=" << q3 << endl;
	cout << endl;

	q1 = q1 + q3; cout << "*q1 = q1 + q3\nq1=" << q1 << endl;
	cout << "q1.Size()=" << q1.Size() << endl;
	cout << "q1.IsEmpty()=" << ((q1.IsEmpty()) ? "T" : "F") << endl;
	cout << "q1.IsFull()=" << ((q1.IsFull()) ? "T" : "F") << endl;
	cout << "q1.Peek()=" << q1.Peek() << endl;
	cout << endl;

	q1 = Queue<int>(); q1 = q1 + q3; cout << "*set q1 to 0 then q1 = q1 + q3\nq1=" << q1 << endl;
	cout << endl;
	q1 = q1 + q3; cout << "q1 += q3;\nq1=" << q1 << endl; // test +=
	cout << "q1.Size()=" << q1.Size() << endl;
	cout << "q1.IsEmpty()=" << ((q1.IsEmpty()) ? "T" : "F") << endl;
	cout << "q1.IsFull()=" << ((q1.IsFull()) ? "T" : "F") << endl;
	cout << "q1.Peek()=" << q1.Peek() << endl;
	cout << endl;

	cout << "q1=" << q1 << "\nq2=" << q2 << "\nq3=" << q3 << endl;
	cout << "q3.Peek()=" << q3.Peek() << endl;
	cout << endl;
	for (int i=8; i>0; i--)
		q3.Enqueue(i);
	cout << "*enqueue q3 8 times with i (backwards)\nq3=" << q3 << endl;
	cout << "q3.Peek()=" << q3.Peek() << endl;
	cout << endl;
	q3 = q3 + q1; cout << "*q3 += q1\nq3=" << q3 << endl;
	cout << "q3.Size()=" << q3.Size() << endl;
	cout << "q3.IsEmpty()=" << ((q3.IsEmpty()) ? "T" : "F") << endl;
	cout << "q3.IsFull()=" << ((q3.IsFull()) ? "T" : "F") << endl;
	cout << "q3.Peek()=" << q3.Peek() << endl;
	cout << endl;

	Queue<char> q4;
	for (char c='a'; c<='z'; c++)
		q4.Enqueue(c);
	cout << "q4=" << q4 << endl;
	cout << "q4.Size()=" << q4.Size() << endl;
	cout << "q4.IsEmpty()=" << ((q4.IsEmpty()) ? "T" : "F") << endl;
	cout << "q4.IsFull()=" << ((q4.IsFull()) ? "T" : "F") << endl;
	cout << "q4.Peek()=" << q4.Peek() << endl;

	return 0;
}
