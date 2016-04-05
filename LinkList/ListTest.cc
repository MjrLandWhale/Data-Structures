/******************************************
 * YOU MAY NOT CHANGE THIS FILE IN ANY WAY!
 ******************************************/
#include <iostream>
#include "List.cc"
using namespace std;

int main()
{
	List a, b;

	cout << " 1 " << a.GetValue() << endl;
	cout << " 2 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	cout << " 3 " << "b(" << b.GetSize() << "/" << b.GetPos() << ") = " << b << endl;
	for (int i=1; i<=25; i++)
	{
		a.InsertAfter(i);
		b.InsertBefore(i);
	}
	cout << " 4 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	cout << " 5 " << "b(" << b.GetSize() << "/" << b.GetPos() << ") = " << b << endl;
	List c(a);
	cout << " 6 " << "c(" << c.GetSize() << "/" << c.GetPos() << ") = " << c << endl;
	a.Remove();
	a.Remove();
	for (int i=0; i<5; i++)
		a.Prev();
	a.Remove();
	a.Remove();
	cout << " 7 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	a.First();
	a.Remove();
	for (int i=0; i<a.GetSize()/2; a.Next(),i++)
	{
		a.Replace(a.GetValue()*5);
		a.Next();
	}
	cout << " 8 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	a.Last();
	a.Next();
	a.Next();
	a.Remove();
	cout << " 9 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	a.SetPos(a.GetSize()*2/3);
	a.Replace(a.GetValue()*12345);
	cout << "10 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	a.SetPos(a.GetSize());
	a.Remove();
	cout << "11 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	a.SetPos(a.GetSize()-1);
	a.Remove();
	cout << "12 " << "a is " << (!a.IsEmpty() ? "not " : "") << "empty\n";
	cout << "13 " << "a is " << (!a.IsFull() ? "not " : "") << "full\n";
	for (int i=0; i<1000; i++)
		a.InsertBefore(i);
	cout << "14 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	cout << "15 " << "c(" << c.GetSize() << "/" << c.GetPos() << ") = " << c << endl;
	cout << "16 " << "a is " << (!a.IsEmpty() ? "not " : "") << "empty\n";
	cout << "17 " << "a is " << (!a.IsFull() ? "not " : "") << "full\n";
	List d(a);
	cout << "18 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	cout << "19 " << "d(" << d.GetSize() << "/" << d.GetPos() << ") = " << d << endl;
	cout << "20 " << "a " << ((a == d) ? "==" : "!=") << " d\n";
	a.Remove();
	cout << "21 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	cout << "22 " << "d(" << d.GetSize() << "/" << d.GetPos() << ") = " << d << endl;
	cout << "23 " << "a " << ((a != d) ? "!=" : "==") << " d\n";
	a = c;
	c.Remove();
	cout << "24 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	cout << "25 " << "b(" << b.GetSize() << "/" << b.GetPos() << ") = " << b << endl;
	cout << "26 " << "c(" << c.GetSize() << "/" << c.GetPos() << ") = " << c << endl;
	cout << "27 " << "a " << ((a == c) ? "==" : "!=") << " c\n";
	List e = b + a;
	cout << "28 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	cout << "29 " << "b(" << b.GetSize() << "/" << b.GetPos() << ") = " << b << endl;
	cout << "30 " << "e(" << e.GetSize() << "/" << e.GetPos() << ") = " << e << endl;
	for (int i=0; i<1000; i++)
	{
		b.Remove();
		c.Remove();
	}
	cout << "31 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	cout << "32 " << "b(" << b.GetSize() << "/" << b.GetPos() << ") = " << b << endl;
	cout << "33 " << "c(" << c.GetSize() << "/" << c.GetPos() << ") = " << c << endl;
	cout << "34 " << "e(" << e.GetSize() << "/" << e.GetPos() << ") = " << e << endl;
	List f = b + a;
	cout << "35 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	cout << "36 " << "b(" << b.GetSize() << "/" << b.GetPos() << ") = " << b << endl;
	cout << "37 " << "f(" << f.GetSize() << "/" << f.GetPos() << ") = " << f << endl;

	return 0;
}
