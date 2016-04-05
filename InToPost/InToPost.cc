#include <iostream>
// these additional includes may prove useful
#include <cmath>
#include <cstring>
using namespace std;
const int MAX_SIZE=50;
// this class implements a generic list using a linked list as the backend
template <class l_type>
class List
{
	private:
		// list node definition
		struct Node
		{
			l_type data;
			Node *link;
		};

		Node *head;	// the head of the list
		Node *tail;	// the tail of the list
		Node *curr;	// the current position in the list
		int num_items;	// the number of items in the list
//		const int MAX_SIZE=50;

	public:
		// constructor
		// remember that an empty list has a "size" of -1 and its "position" is at -1
		List()
		{
			head = tail = curr = NULL;
			num_items = 0;
		}

		// copy constructor
		// clones the list l and sets the last element as the current
		List(const List& l)
		{
			*this = l;
		}

		// copy constructor
		// clones the list l and sets the last element as the current
		void operator=(const List& l)
		{
			Node *n = l.head;

			head = tail = curr = NULL;
			num_items = 0;

			// just loop through the list and copy each element
			while (n != NULL)
			{
				InsertAfter(n->data);
				n = n->link;
			}
		}

		// navigates to the beginning of the list
		void First()
		{
			curr = head;
		}

		// navigates to the end of the list
		// the end of the list is at the last valid item in the list
		void Last()
		{
			curr = tail;
		}

		// navigates to the specified element (0-index)
		// this should not be possible for an empty list
		// this should not be possible for invalid positions
		void SetPos(int pos)
		{
			if (!IsEmpty() && pos >=0 && pos < num_items)
			{
				curr = head;

				// move curr to the specified position
				for (int i=0; i<pos; i++)
					curr = curr->link;
			}
		}

		// navigates to the previous element
		// this should not be possible for an empty list
		// there should be no wrap-around
		void Prev()
		{
			if (!IsEmpty() && curr != head)
			{
				Node *n = head;

				// move n to the previous element
				while (n->link != curr)
					n = n->link;

				curr = n;
			}
		}

		// navigates to the next element
		// this should not be possible for an empty list
		// there should be no wrap-around
		void Next()
		{
			if (!IsEmpty() && curr != tail)
				curr = curr->link;
		}

		// returns the location of the current element (or -1)
		int GetPos()
		{
			if (IsEmpty())
				return -1;

			Node *n = head;
			int i = 0;

			// traverse the list to get the current position
			while (n != curr)
			{
				n = n->link;
				i++;
			}

			return i;
		}

		// returns the value of the current element (or -1)
		l_type GetValue()
		{
			return ((!IsEmpty()) ? curr->data : -1);
		}

		// returns the size of the list
		// size does not imply capacity
		int GetSize()
		{
			return num_items;
		}

		// inserts an item before the current element
		// the new element becomes the current
		// this should not be possible for a full list
		void InsertBefore(l_type data)
		{
			if (!IsFull())
			{
				// if the list is empty, just insert after
				if (IsEmpty())
					InsertAfter(data);
				else
				{
					// if we're at the beginning, just create a new head that points to the current one
					if (curr == head)
					{
						head = new Node;
						head->data = data;
						head->link = curr;
						curr = head;
						num_items++;
					}
					// otherwise, navigate to the previous node and insert after
					else
					{
						Prev();
						InsertAfter(data);
					}
				}
			}
		}

		// inserts an item after the current element
		// the new element becomes the current
		// this should not be possible for a full list
		void InsertAfter(l_type data)
		{
			if (!IsFull())
			{
				Node *n = new Node;

				n->data = data;
				n->link = NULL;

				// if the list is empty, everything points to the single node
				if (IsEmpty())
					head = tail = curr = n;
				else
				{
					// if we're at the end, just tack the new node on
					if (curr == tail)
					{
						curr->link = n;
						curr = tail = n;
					}
					// otherwise, change the links to insert the node
					else
					{
						n->link = curr->link;
						curr = curr->link = n;
					}
				}

				num_items++;
			}
		}

		// removes the current element (collapsing the list)
		// this should not be possible for an empty list
		void Remove()
		{
			if (!IsEmpty())
			{
				// if we're at the beginning, reset the head
				if (curr == head)
				{
					head = curr = curr->link;

					if (head == NULL)
						tail = NULL;
				}
				else
				{
					Prev();
					// and rearrange the pointer to remove this node
					curr->link = curr->link->link;
					// we handle removing the tail vs. other internal nodes a bit differently
					if (curr->link == NULL)
						tail = curr;
					Next();
				}
				num_items--;
			}
		}

		// replaces the value of the current element with the specified value
		// this should not be possible for an empty list
		void Replace(l_type data)
		{
			if (!IsEmpty())
				curr->data = data;
		}

		// returns if the list is empty
		bool IsEmpty()
		{
			return (head == NULL);
		}

		// returns if the list is full
		bool IsFull()
		{
			return (num_items == MAX_SIZE);
		}

		// returns the concatenation of two lists
		// l should not be modified
		// l should be concatenated to the end of *this
		// the returned list should not exceed MAX_SIZE elements
		// the last element of the new list is the current
		List operator+(const List& l) const
		{
			// copy the first list
			List t = *this;
			Node *n = l.head;

			// iterate through the second list and copy each element to the new list
			while (n != NULL && !t.IsFull())
			{
				t.InsertAfter(n->data);
				n = n->link;
			}

			return t;
		}

		// returns if two lists are equal (by value)
		bool operator==(const List& l) const
		{
			// the lists are not equal if they're of different sizes
			if (num_items != l.num_items)
				return false;

			Node *p = head;
			Node *q = l.head;

			// iterate through each list
			while (p != NULL)
			{
				// if any pair of elements differ, the lists are not equal
				if (p->data != q->data)
					return false;
				p = p->link;
				q = q->link;
			}

			return true;
		}

		// returns if two lists are not equal (by value)
		bool operator!=(const List& l) const
		{
			return !(*this == l);
		}

		// returns a string representation of the entire list (e.g., 1 2 3 4 5)
		// the string "NULL" should be returned for an empty list
		friend ostream& operator<<(ostream& out, const List &l)
		{
			// "NULL" if the list is empty
			if (l.head == NULL)
				out << "NULL";
			else
			{
				Node *n = l.head;

				// otherwise iterate through the list and display each element separated by a space
				while (n != NULL)
				{
					out << n->data;
					n = n->link;
				}
			}

			return out;
		}
};

// this class implements a stack that makes use of the above generic list
template <class s_type>
class Stack
{
	private:
		List<s_type> list;

	public:
		//Basic constructor.
		//List backend is already implemented, so there is nothing here
		Stack<s_type>()
		{
		}
		//Copy Constructor
		//Utilizes Generic List implementation of constructors
		//So we just tell it to copy the only private Stack variable
		Stack(const Stack& s)
		{
			list = s.list;
		}
		//Equal operator overload
		//Implemented for our List backend, so easy game easy life
		void operator=(const Stack& s)
		{
			list = s.list;
		}
		//Pushes a data value onto the top of the stack
		void Push(s_type data)
		{
			list.First();
			list.InsertBefore(data);
		}
		//"Pops" the newest member of the stack off,
		//returning the value stored, and removing it
		//from the stack
		s_type Pop()
		{

			s_type temp = Peek();
			list.Remove();
			return temp;
		}
		//Sneaks past you like a ninja
		//and tells you what value is resting at the
		//top of the stack, without disturbing
		//its delicate slumber
		s_type Peek()
		{
			list.First();
			return list.GetValue();
		}
		//Returns the size of the stack
		//(really the size of the list backend)
		int Size()
		{
			return list.GetSize();
		}
		//Returns true if the stack is empty,
		//false otherwise
		bool IsEmpty()
		{
			return list.IsEmpty();
		}
		//Its almost like the "bool" tag at the
		//front tells you something, like that
		//it will be true or false, based off whether
		//or not the stack is full
		bool IsFull()
		{
			return list.IsFull();
		}
		//Adds two stacks together,
		//returning the second stack, appended
		//to the end of the first stack
		Stack operator+(const Stack& s)const
		{
			/*	Stack<s_type> ret = *this;
				ret.list.Last();
				ret.list=list+s.list;
				return ret;
			*/
			Stack<s_type> ret;
			ret.list = this->list + s.list;
			return ret;

		}
		//True if the two stacks are equal at all
		//locations and values, false otherwise
		bool operator==(const Stack& s)const
		{
			return list == s.list;
		}
		//Same as above, but in reverse.  True if
		//not the same, false if the same
		bool operator!=(const Stack& s)const
		{
			return !(list == s.list);
		}
		//Friendly helper method that allows us to
		//print the values stored within stacks, because
		//normally printing these lists doesnt work,
		//so we give it some help
		friend ostream& operator<<(ostream& out, const Stack& s)
		{
			out << s.list;
			return out;
		}
};

// this class implements a queue that makes use of the above generic list
template <class q_type>
class Queue
{
	private:
		List<q_type> list;

	public:
		//Basic constructor.
		//List backend is already implemented, so there is nothing here
		Queue<q_type>()
		{
		}
		//Copy Constructor
		//Utilizes Generic List implementation of constructors
		//So we just tell it to copy the only private Queue variable
		Queue(const Queue& q)
		{
			list = q.list;
		}
		//Equal operator overload
		//Implemented for our List backend, so easy game easy life
		void operator=(const Queue& q)
		{
			list = q.list;
		}
		//Enqueues a value to the end of the queue
		//Like a good british gentleman, it waits at the
		//end until it reaches the fron of the line
		//in order to be dequeued
		void Enqueue(q_type data)
		{
			list.Last();
			list.InsertAfter(data);
		}
		//Dequeues a value from the front of the queue
		//Its like your dream come true when waiting
		//at the DMV, you are finally next in line,
		//and all your suffering may be worth it,
		//until you realize you forgot your birth certificate
		q_type Dequeue()
		{
			list.First();
			q_type temp = list.GetValue();
			list.Remove();
			return temp;

		}
		//Sneaks past you like a ninja
		//and tells you what value is resting at the
		//top of the stack, without disturbing
		//its delicate slumber
		q_type Peek()
		{
			list.First();
			return list.GetValue();
		}
		//Returns the size of the queue
		//(really the size of the list backend)
		int Size()
		{
			return list.GetSize();
		}
		//Returns true if the queue is empty,
		//false otherwise
		bool IsEmpty()
		{
			return list.IsEmpty();
		}
		//Its almost like the "bool" tag at the
		//front tells you something, like that
		//it will be true or false, based off whether
		//or not the queue is full.  True if full btw
		bool IsFull()
		{
			return list.IsFull();
		}
		//Adds two queues together,
		//returning the second queue, appended
		//to the end of the first queue
		Queue operator+(const Queue& q)const
		{
			Queue<q_type> ret;
			ret.list = this->list + q.list;
			return ret;

		}
		//True if the two queues are equal at all
		//locations and values, false otherwise
		bool operator==(const Queue& q)const
		{
			return list == q.list;
		}
		//Same as above, but in reverse.  True if
		//not the same, false if the same
		bool operator!=(const Queue& q)const
		{
			return !(list == q.list);
		}
		//Friendly helper method that allows us to
		//print the values stored within queues, because
		//normally printing these lists doesnt work,
		//so we give it some help
		friend ostream& operator<<(ostream& out, const Queue& q)
		{
			out << q.list;
			return out;
		}
};

// function prototypes
Queue<char> Convert(Queue<char>&);
double Calculate(Queue<char>&);
bool IsOperand(char);
int InfixPriority(char);
int StackPriority(char);

Stack<char> operS;
// **MAIN**
// the main method is just a driver!
int main()
{
	char line[256];
//	Stack<char> operS;
	// read a line of input
	// keep reading until there are no more lines
	while (cin.getline(line, 256))
	{
		Queue<char> infix;
		Queue<char> postfix;
		// enqueue each character of the line to the infix queue
		for (int i=0; i<strlen(line); i++)
			infix.Enqueue(line[i]);
		// display the infix queue (expression)
		cout << infix << endl;
		// convert the infix expression to postfix
		postfix = Convert(infix);
		// display the postfix queue (expression)
		cout << postfix << endl;
		// calculate and display the result of the postfix expression
		cout << Calculate(postfix) << endl << endl;
	}

	return 0;
}

// Given an infix queue, this method converts it to a postfix queue
Queue<char> Convert(Queue<char>& infix)
{	
	Queue<char> post;
//	char tokenVal=infix.Dequeue();
	while(!infix.IsEmpty())
	{
		char tokenVal=infix.Dequeue();
	//	Queue<char>post;
//cout << tokenVal << endl;
		if(IsOperand(tokenVal))
		{
//cout<< "I think this is an operand" << endl;
			post.Enqueue(tokenVal);
		}
//cout << "Its not an Operand, and it has priority " << InfixPriority(tokenVal) << endl;
		else if(tokenVal == ')')
		{
//cout << "I found a Parenthesis" << endl;
			char op=operS.Pop();
			while(op!='(')
			{
//cout << "I havent found the Parenthesis end" << endl;
				post.Enqueue(op);
				op=operS.Pop();
			}
//cout << "Found you, bitch" << endl;
		}
		else
		{
//cout << "Its an operator" << endl;
			char op=operS.Peek();
			while (StackPriority(op) >= InfixPriority(tokenVal))
			{
				op=operS.Pop();
				post.Enqueue(op);
				op=operS.Peek();
			}
			operS.Push(tokenVal);
		}
	}
	while(!operS.IsEmpty())
	{
		char op=operS.Pop();
		post.Enqueue(op);
	}
	return post;	
}

// given a postfix queue, this method calculates the numeric result using a stack
double Calculate(Queue<char>& postfix)
{
	double ret;
	Stack<double> evalStack;
	while(!postfix.IsEmpty())
	{
		char token=postfix.Dequeue();
		if(IsOperand(token))
		{
			double val= token - '0';
//cout << "Operand has a value of" << val << endl;
			evalStack.Push(val);
		}
		else
		{
			double a=evalStack.Pop();
			double b=evalStack.Pop();
			switch (token)
			{
				case '^':
					evalStack.Push(pow(b,a));
					break;
				case '*':
					evalStack.Push(a*b);
					break;
				case '/':
					evalStack.Push(b/a);
					break;
				case '+':
					evalStack.Push(a+b);
					break;
				case '-':
					evalStack.Push(b-a);
					break;
			}
		
		}
		
	}
	return evalStack.Pop();
}

// given a character from an expression, this method determines whether or not it is an operand
bool IsOperand(char c)
{
	int check = (int) c;
	if(47<check && check<58)
		return true;
	return false;
	
}

// given a character that represents an operator from an expression, this method returns its infix priority
int InfixPriority(char c)
{
	switch (c)
	{
		case '(':
			return 4;
		case '^':
			return 3;
		case '*': case '/':
			return 2;
		case '+': case '-':
			return 1;
		default:
			return 0;
	}
}

// given a character that represents an operator from an expression, this method returns its stack priority
int StackPriority(char c)
{
	switch (c)
	{
		case '^': case '*': case '/':
			return 2;
		case '+': case '-':
			return 1;
		default:
			return 0;
	}
}
