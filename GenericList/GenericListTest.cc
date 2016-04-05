
#include <iostream>
#include "GenericList.cc"
using namespace std;

/*****************************************
 * YOU MAY NOT CHANGE ANYTHING BELOW THIS!
 *****************************************/
int main()
{
	List<int>a, b;

	cout << " 0 " << a.GetValue() << endl;
	cout << " 1 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	cout << " 2 " << "b(" << b.GetSize() << "/" << b.GetPos() << ") = " << b << endl;
	for (int i=1; i<=25; i++)
	{
		a.InsertAfter(i);
		b.InsertBefore(i);
	}
	cout << " 3 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	cout << " 4 " << "b(" << b.GetSize() << "/" << b.GetPos() << ") = " << b << endl;
	List<int>c(a);
	cout << " 5 " << "c(" << c.GetSize() << "/" << c.GetPos() << ") = " << c << endl;
	a.Remove();
	a.Remove();
	for (int i=0; i<5; i++)
		a.Prev();
	a.Remove();
	a.Remove();
	cout << " 6 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	a.First();
	a.Remove();
	for (int i=0; i<a.GetSize()/2; a.Next(),i++)
	{
		a.Replace(a.GetValue()*5);
		a.Next();
	}
	cout << " 7 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	a.Last();
	a.Next();
	a.Next();
	a.Remove();
	cout << " 8 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	a.SetPos(a.GetSize()*2/3);
	a.Replace(a.GetValue()*12345);
	cout << " 9 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	a.SetPos(a.GetSize());
	a.Remove();
	cout << "10 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	a.SetPos(a.GetSize()-1);
	a.Remove();
	cout << "11 " << "a is " << (!a.IsEmpty() ? "not " : "") << "empty\n";
	cout << "12 " << "a is " << (!a.IsFull() ? "not " : "") << "full\n";
	for (int i=0; i<1000; i++)
		a.InsertBefore(i);
	cout << "13 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	cout << "14 " << "c(" << c.GetSize() << "/" << c.GetPos() << ") = " << c << endl;
	cout << "15 " << "a is " << (!a.IsEmpty() ? "not " : "") << "empty\n";
	cout << "16 " << "a is " << (!a.IsFull() ? "not " : "") << "full\n";
	List<int>d(a);
	cout << "17 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	cout << "18 " << "d(" << d.GetSize() << "/" << d.GetPos() << ") = " << d << endl;
	cout << "19 " << "a " << ((a == d) ? "==" : "!=") << " d\n";
	a.Remove();
	cout << "20 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	cout << "21 " << "d(" << d.GetSize() << "/" << d.GetPos() << ") = " << d << endl;
	cout << "22 " << "a " << ((a != d) ? "!=" : "==") << " d\n";
	a = c;
	c.Remove();
	cout << "23 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	cout << "24 " << "b(" << b.GetSize() << "/" << b.GetPos() << ") = " << b << endl;
	cout << "25 " << "c(" << c.GetSize() << "/" << c.GetPos() << ") = " << c << endl;
	cout << "26 " << "a " << ((a == c) ? "==" : "!=") << " c\n";
	List<int>e = b + a;
	cout << "27 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	cout << "28 " << "b(" << b.GetSize() << "/" << b.GetPos() << ") = " << b << endl;
	cout << "29 " << "e(" << e.GetSize() << "/" << e.GetPos() << ") = " << e << endl;
	for (int i=0; i<1000; i++)
	{
		b.Remove();
		c.Remove();
	}
	cout << "30 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	cout << "31 " << "b(" << b.GetSize() << "/" << b.GetPos() << ") = " << b << endl;
	cout << "32 " << "c(" << c.GetSize() << "/" << c.GetPos() << ") = " << c << endl;
	cout << "33 " << "e(" << e.GetSize() << "/" << e.GetPos() << ") = " << e << endl;
	List<int>f = b + a;
	cout << "34 " << "a(" << a.GetSize() << "/" << a.GetPos() << ") = " << a << endl;
	cout << "35 " << "b(" << b.GetSize() << "/" << b.GetPos() << ") = " << b << endl;
	cout << "36 " << "f(" << f.GetSize() << "/" << f.GetPos() << ") = " << f << endl;

	List<char> g;
	for (char i='a'; i<='m'; i++)
	{
//		cout << "37 " << "g(" << g.GetSize() << "/" << g.GetPos() << ") = " << g << endl;
		g.InsertAfter(i);
//		cout << "37 " << "g(" << g.GetSize() << "/" << g.GetPos() << ") = " << g << endl;
		g.InsertBefore(i+13);
	}
	cout << "37 " << "g(" << g.GetSize() << "/" << g.GetPos() << ") = " << g << endl;

	List<float> h;
	for (float i=2.71828; i<=3.14159; i+=.111)
		h.InsertAfter(i);
	h.InsertBefore(3.14159);
	cout << "38 " << "h(" << h.GetSize() << "/" << h.GetPos() << ") = " << h << endl;

	return 0;
}
