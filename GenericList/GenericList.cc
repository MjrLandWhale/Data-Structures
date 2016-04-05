/****************************************************
 *  Mitchell Brandone
 * 10-16-15
 * Generic List
 *
 * An easy list program which uses a link list as
 * the backend of the program
 ****************************************************/

#include <iostream>
using namespace std;

const int MAX_SIZE = 30;

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

	public:
		// constructor
		// remember that an empty list has a "size" of -1 and its "position" is at -1
		List()
		{
			//Set Everything to its default value of "empty"
			num_items = 0;
			head = NULL;
			tail = NULL;
			curr = NULL;
		}

		// copy constructor
		// clones the list l and sets the last element as the current
		List(const List& l)
		{
			//Begin by making current list empty
			num_items = 0;
			head = tail = curr = NULL;
			Node* p = l.head;
			//Insert each value from l into next position of current list
			while(p != NULL)
			{
				InsertAfter(p->data);
				p = p->link;
			}
		}

		// copy constructor
		// clones the list l and sets the last element as the current
		//This could be done using our other copy constructor, but it kept getting angry at me
		void operator=(const List& l)
		{
			//Make current list empty
			num_items = 0;
			head = tail = curr = NULL;
			Node* p = l.head;
			//Insert each value from l into next position of current list
			while(p != NULL)
			{
				InsertAfter(p->data);
				p = p->link;
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
			int counter = 0;
			Node* p = head;
			if(!IsEmpty() && pos < num_items)
			{
				//Traverse the list to the desired position
				while(counter < pos && counter < MAX_SIZE)
				{
					p = p->link;
					counter++;
				}
				//set current node to desired node
				curr = p;


			}




		}

		// navigates to the previous element
		// this should not be possible for an empty list
		// there should be no wrap-around
		// Back it up *Beep-Beep*
		void Prev()
		{
			if(curr != head)
			{
				Node* p = head;
				while(p->link != curr)
					p = p->link;
				curr = p;
			}
		}

		// navigates to the next element
		// this should not be possible for an empty list
		// there should be no wrap-around
		//Its like driving up to the next stop light
		void Next()
		{
			if(curr != tail && !IsEmpty())
				curr = curr->link;
		}

		// returns the location of the current element (or -1)
		int GetPos()
		{
			//return -1 for an empty list
			if(IsEmpty())
				return -1;
			else
			{
				//traverse through list until you get to current
				int pos = 0;
				Node* p = head;
				while(p != curr)
				{
					p = p->link;
					pos++;
				}
				return pos;
			}
		}

		// returns the value of the current element (or -1)
		l_type GetValue()
		{
			if(IsEmpty())
				return -1;
			else
				return curr->data;
			//equivalent to *curr.data;
		}

		// returns the size of the list
		// size does not imply capacity
		int GetSize() const
		{
			return num_items;
		}

		// inserts an item before the current element
		// the new element becomes the current
		// this should not be possible for a full list
		void InsertBefore(l_type data)
		{
			if(!IsFull())
			{
				if(IsEmpty())
					InsertAfter(data);
				else
				{
					//account for the spooky code magic
					//that happens when head==curr
					if(head == curr)
					{
						curr = new Node;
						curr->data = data;
						curr->link = head;
						head = curr;
					//	curr=head->link;
						num_items++;
					}
					else
					{
						Prev();
						InsertAfter(data);
					//	Next();
					//	Next();
					}
				}
			}

		}

		// inserts an item after the current element
		// the new element becomes the current
		// this should not be possible for a full list
		void InsertAfter(l_type data)
		{
			if(!IsFull())
			{
				//Add when list is empty
				if(IsEmpty())
				{
					head = new Node;
					head->data = data;
					head->link = NULL;
					curr = head;
					tail = head;
//					num_items++;
				}
				else
				{
					//special case when at end of list
					if(curr == tail)
					{
						curr->link = new Node;
						curr = curr->link;
						curr->data = data;
						curr->link = NULL;
						tail = curr;
//						num_items++;
					}
					//normal case
					else
					{
						Node* p = new Node;
						p->data = data;
						p->link = curr->link;
						curr->link = p;
						curr=p;
//						num_items++;
					}
				}
			}
			num_items++;

		}

		// removes the current element (collapsing the list)
		// this should not be possible for an empty list
		void Remove()
		{
			if(!IsEmpty())
			{
				if(curr == tail)
				{
					Prev();
					curr->link = NULL;
					tail = curr;
				}
				else if(curr == head)
				{
					curr = curr->link;
					head = curr;
				}
				else
				{
					Prev();
					curr->link = curr->link->link;
					Next();
				}
				num_items--;
			}
			// These lines ensure that an empty list is truly empty,
			// and doesnt have a value left in it
			if(IsEmpty())
				curr = head = tail = NULL;
		}
		// replaces the value of the current element with the specified value
		// this should not be possible for an empty list
		void Replace(l_type data)
		{
			if(!IsEmpty())
			{
				//easy enough.  We dont change any locations, just a value
				curr->data = data;
			}

		}

		// returns if the list is empty
		bool IsEmpty()
		{
			return (num_items == 0);
		}

		// returns if the list is full
		bool IsFull()
		{
			return(num_items == MAX_SIZE);
		}

		// returns the concatenation of two lists
		// l should not be modified
		// l should be concatenated to the end of *this
		// the returned list should not exceed MAX_SIZE elements
		// the last element of the new list is the current
		List operator+(const List& l) const
		{
			List ret(*this);
			//catch if first list is empty, and returns
			//Only the second list (Optimization)
			if(ret.IsEmpty())
			{
				ret = l;
				return ret;
			}
			ret.Last();
			Node* p = l.head;
			//Traverse the List l until full or fully traversed
			//and insert values into the return list
			while(ret.GetSize() != MAX_SIZE && p->link != NULL)
			{
				ret.InsertAfter(p->data);
				p = p->link;
			}
			return ret;
		}

		// returns if two lists are equal (by value)
		bool operator==(const List& l) const
		{
			//Cant be equivalent if they arent the same length
			if(GetSize() == l.GetSize())
			{
				Node* p = head;
				Node* q = l.head;
				//Iterate through each position of both lists
				do
				{
					//If we catch 2 unequal data values, return false
					if(p->data != q->data)
						return false;
					p = p->link;
					q = q->link;

				}
				while(p != NULL);
				//true if same size, and all values are equivalent
				return true;
			}
			return false;
		}

		// returns if two lists are not equal (by value)
		bool operator!=(const List& l) const
		{
			//return not ==
			return !(*this == l);
		}

		// returns a string representation of the entire list (e.g., 1 2 3 4 5)
		// the string "NULL" should be returned for an empty list
		friend ostream& operator<<(ostream& out, const List &l)
		{
			//empty list return Null
			if(l.num_items == 0)
				out << "NULL";
			else
			{
				//note this is a helper method, therefore we must ask for the head of a specific list passed in (l)
				Node* p = l.head;
				//Traverse the list, printing each value as we go
				while(p != NULL)
				{
					out << p->data << " ";
					p = p->link;
				}
			}
			return out;


		}
};
