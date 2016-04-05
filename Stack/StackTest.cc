#include <iostream>
#include "Stack.cc"
using namespace std;

/*****************************************
 * YOU MAY NOT CHANGE ANYTHING BELOW THIS!
 *****************************************/
int main()
{
	Stack<int> s1;

	cout << "*declare stack s1\ns1=" << s1 << endl; // stack initially set to 0
	cout << "s1.Size()=" << s1.Size() << endl;
	cout << "s1.IsEmpty()=" << ((s1.IsEmpty()) ? "T" : "F") << endl;
	cout << "s1.IsFull()=" << ((s1.IsFull()) ? "T" : "F") << endl;
	cout << "s1.Peek()=" << s1.Peek() << endl;
	cout << endl;

	for (int i=0; i<1000; i++) // push 1000 times with i+100
		s1.Push(i+100);
	cout << "*Push(i+100) 1000 times\ns1=" << s1 << endl;
	cout << "s1.Size()=" << s1.Size() << endl;
	cout << "s1.IsEmpty()=" << ((s1.IsEmpty()) ? "T" : "F") << endl;
	cout << "s1.IsFull()=" << ((s1.IsFull()) ? "T" : "F") << endl;
	cout << "s1.Peek()=" << s1.Peek() << endl;
	cout << endl;

	for (int i=0; i<10; i++) // pop 10 times
		s1.Pop();
	cout << "*pop 10 times\ns1=" << s1 << endl;
	cout << "s1.Size()=" << s1.Size() << endl;
	cout << "s1.IsEmpty()=" << ((s1.IsEmpty()) ? "T" : "F") << endl;
	cout << "s1.IsFull()=" << ((s1.IsFull()) ? "T" : "F") << endl;
	cout << "s1.Peek()=" << s1.Peek() << endl;
	cout << endl;

	for (int i=0; i<1000; i++) // pop 1000 times
		s1.Pop();
	cout << "*pop 1000 times\ns1=" << s1 << endl;
	cout << "s1.Size()=" << s1.Size() << endl;
	cout << "s1.IsEmpty()=" << ((s1.IsEmpty()) ? "T" : "F") << endl;
	cout << "s1.IsFull()=" << ((s1.IsFull()) ? "T" : "F") << endl;
	cout << "s1.Peek()=" << s1.Peek() << endl;
	cout << endl;

	for (int i=0; i<10; i++) // push 10 times with i*i
		s1.Push(i*i);
	cout << "*push 10 times with i*i\ns1=" << s1 << endl;
	cout << "s1.Size()=" << s1.Size() << endl;
	cout << "s1.IsEmpty()=" << ((s1.IsEmpty()) ? "T" : "F") << endl;
	cout << "s1.IsFull()=" << ((s1.IsFull()) ? "T" : "F") << endl;
	cout << "s1.Peek()=" << s1.Peek() << endl;
	cout << endl;

	Stack<int> s2(s1); // s2 declared as a copy of s1
	cout << "*declare s2 as a copy of s1 (stack s2(s1))\ns2=" << s2 << endl;
	cout << "s2.Size()=" << s2.Size() << endl;
	cout << "s2.IsEmpty()=" << ((s2.IsEmpty()) ? "T" : "F") << endl;
	cout << "s2.IsFull()=" << ((s2.IsFull()) ? "T" : "F") << endl;
	cout << "s2.Peek()=" << s2.Peek() << endl;
	cout << endl;

	Stack<int> s3;
	s3 = s3 + s2;
	cout << "*declare s3 as a copy of s2 (stack s3 = s2)\ns3=" << s3 << endl; // copy constructor (=)
	cout << "s3.Size()=" << s3.Size() << endl;
	cout << "s3.IsEmpty()=" << ((s3.IsEmpty()) ? "T" : "F") << endl;
	cout << "s3.IsFull()=" << ((s3.IsFull()) ? "T" : "F") << endl;
	cout << "s3.Peek()=" << s3.Peek() << endl;
	cout << endl;

	s2 = Stack<int>();
	cout << "*reset s2 to 0\ns2=" << s2 << endl; // reset stack to 0
	cout << "s2.Size()=" << s2.Size() << endl;
	cout << "s2.IsEmpty()=" << ((s2.IsEmpty()) ? "T" : "F") << endl;
	cout << "s2.IsFull()=" << ((s2.IsFull()) ? "T" : "F") << endl;
	cout << "s2.Peek()=" << s2.Peek() << endl;
	cout << endl;

	cout << "s1=" << s1 << "\ns2=" << s2 << "\ns3=" << s3 << endl;
	cout << "s1 == s2; =" << ((s1 == s2) ? "T" : "F") << endl; // test ==
	cout << "s1 == s3; =" << ((s1 == s3) ? "T" : "F") << endl;
	cout << "s1 != s3; =" << ((s1 != s3) ? "T" : "F") << endl;
	cout << endl;

	s1 = s1 + s2;
	cout << "*s1 = s1 + s2\ns1=" << s1 << endl; // test +
	cout << "s1.Size()=" << s1.Size() << endl;
	cout << "s1.IsEmpty()=" << ((s1.IsEmpty()) ? "T" : "F") << endl;
	cout << "s1.IsFull()=" << ((s1.IsFull()) ? "T" : "F") << endl;
	cout << "s1.Peek()=" << s1.Peek() << endl;
	cout << endl;

	for (int i=0; i<5; i++)
		s1.Pop();
	cout << "*pop s1 5 times\n";
	cout << "s1=" << s1 << "\ns2=" << s2 << "\ns3=" << s3 << endl;
	cout << endl;

	s1 = s1 + s3;
	cout << "*s1 = s1 + s3\ns1=" << s1 << endl;
	cout << "s1.Size()=" << s1.Size() << endl;
	cout << "s1.IsEmpty()=" << ((s1.IsEmpty()) ? "T" : "F") << endl;
	cout << "s1.IsFull()=" << ((s1.IsFull()) ? "T" : "F") << endl;
	cout << "s1.Peek()=" << s1.Peek() << endl;
	cout << endl;

	s1 = Stack<int>();
	s1 = s1 + s3;
	cout << "*set s1 to 0 then s1 = s1 + s3\ns1=" << s1 << endl;
	cout << endl;
	s1 = s1 + s3;
	cout << "s1 += s3;\ns1=" << s1 << endl; // test +=
	cout << "s1.Size()=" << s1.Size() << endl;
	cout << "s1.IsEmpty()=" << ((s1.IsEmpty()) ? "T" : "F") << endl;
	cout << "s1.IsFull()=" << ((s1.IsFull()) ? "T" : "F") << endl;
	cout << "s1.Peek()=" << s1.Peek() << endl;
	cout << endl;

	cout << "s1=" << s1 << "\ns2=" << s2 << "\ns3=" << s3 << endl;
	cout << "s3.Peek()=" << s3.Peek() << endl;
	cout << endl;
	for (int i=8; i>0; i--)
		s3.Push(i);
	cout << "*push s3 8 times with i (backwards)\ns3=" << s3 << endl;
	cout << "s3.Peek()=" << s3.Peek() << endl;
	cout << endl;
	s3 = s3 + s1;
	cout << "*s3 += s1\ns3=" << s3 << endl;
	cout << "s3.Size()=" << s3.Size() << endl;
	cout << "s3.IsEmpty()=" << ((s3.IsEmpty()) ? "T" : "F") << endl;
	cout << "s3.IsFull()=" << ((s3.IsFull()) ? "T" : "F") << endl;
	cout << "s3.Peek()=" << s3.Peek() << endl;
	cout << endl;

	Stack<char> s4;
	for (char c='a'; c<='z'; c++)
		s4.Push(c);
	cout << "s4=" << s4 << endl;
	cout << "s4.Size()=" << s4.Size() << endl;
	cout << "s4.IsEmpty()=" << ((s4.IsEmpty()) ? "T" : "F") << endl;
	cout << "s4.IsFull()=" << ((s4.IsFull()) ? "T" : "F") << endl;
	cout << "s4.Peek()=" << s4.Peek() << endl;

	return 0;
}
