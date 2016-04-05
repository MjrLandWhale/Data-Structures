//The Stack class

#include <iostream>
#include "GenericList.cc"
using namespace std;

template <class s_type>
class Stack
{
	private:
		List<s_type> list;
		
	public:
		Stack<s_type>()
		{
		}
		Stack(const Stack& s)
		{
			list=s.list;
		}
		void operator=(const Stack& s)
		{
			list=s.list;
		}
		void Push(s_type data)
		{
			list.First();
			list.InsertBefore(data);
		}
		s_type Pop()
		{
			
			s_type temp=Peek();
			list.Remove();
			return temp;
		}
		s_type Peek()
		{
			list.First();
			return list.GetValue();
		}
		int Size()
		{
			return list.GetSize();
		}
		bool IsEmpty()
		{
			return list.IsEmpty();
		}
		bool IsFull()
		{
			return list.IsFull();
		}
		Stack operator+(const Stack& s)
		{
			Stack<s_type> ret=*this;
			//Stack<s_type> ret2=s;
			ret.list=ret.list + s.list;
			return ret;
		}
		bool operator==(const Stack& s)const
		{
			return list==s.list;
		}
		bool operator!=(const Stack& s)const
		{
			return !(list==s.list);
		}
		friend ostream& operator<<(ostream& out, const Stack& s)
		{
			out << s.list;
			return out;
		}
	

};
