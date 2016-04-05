/****************************************************
 * Mitchell Brandone
 * 10-16-15
 * LinkList
 *
 * An easy list program which uses a link list as 
 * the backend of the program
 ****************************************************/

#include <iostream>
using namespace std;

const int MAX_SIZE = 30;

class List
{
	private:
		// list node definition
		struct Node
		{
			int data;
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
			num_items = 0;
			head=NULL;
			tail=NULL;
			curr=NULL;
		}

		// copy constructor
		// clones the list l and sets the last element as the current
		List(const List& l)
		{
			num_items=0;
			head=tail=curr=NULL;
			Node* p=l.head;
			while(p != NULL)
			{
				InsertAfter(p->data);
				p = p->link;
			}
		}

		// copy constructor
		// clones the list l and sets the last element as the current
		void operator=(const List& l)
		{
		//	*this=List(l);
			num_items=0;
			head=tail=curr=NULL;
			Node* p=l.head;
			while(p!= NULL)
			{
				InsertAfter(p->data);
				p=p->link;
			}
		}

		// navigates to the beginning of the list
		void First()
		{
			curr=head;
		}

		// navigates to the end of the list
		// the end of the list is at the last valid item in the list
		void Last()
		{
			curr=tail;
		}

		// navigates to the specified element (0-index)
		// this should not be possible for an empty list
		// this should not be possible for invalid positions
		void SetPos(int pos)
		{
			int counter=0;
			Node* p=head;
			if(!IsEmpty() && pos<num_items)
			{
				while(counter<pos && counter < MAX_SIZE)
				{
					p=p->link;	
					counter++;	
				}
				curr=p;
				
				
			}
			
			
			
			
		}

		// navigates to the previous element
		// this should not be possible for an empty list
		// there should be no wrap-around
		void Prev()
		{
			if(curr!=head)
			{
				Node* p=head;
				while(p->link!=curr)
					p=p->link;
				curr=p;
			}
		}

		// navigates to the next element
		// this should not be possible for an empty list
		// there should be no wrap-around
		void Next()
		{
			if(curr!=tail && !IsEmpty())
				curr= curr->link;
		}

		// returns the location of the current element (or -1)
		int GetPos()
		{
			if(IsEmpty())
				return -1;
			else
			{
				//traverse through list until you get to current
				int pos = 0;
				Node* p = head;
				while(p!=curr)
				{
					p=p->link;
					pos++;
				}
				return pos;
			}
		}

		// returns the value of the current element (or -1)
		int GetValue()
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
		void InsertBefore(int data)
		{
			if(!IsFull())
			{
				if(IsEmpty())
					InsertAfter(data);
				else
				{
					if(head==curr)
					{
						curr=new Node;
						curr->data=data;
						curr->link=head;
						head=curr;
						num_items++;					
					}
					else
					{
						Prev();
						InsertAfter(data);
						Next();
					}
				}
			}
			
		}

		// inserts an item after the current element
		// the new element becomes the current
		// this should not be possible for a full list
		void InsertAfter(int data)
		{
			if(!IsFull())
			{
				if(IsEmpty())
				{
					head = new Node;
					head->data=data;
					head->link=NULL;
					curr=head;
					tail=head;
//					num_items++;
				}
				else
				{
					if(curr==tail)
					{
						curr->link=new Node;
						curr=curr->link;
						curr->data=data;
						curr->link=NULL;
						tail=curr;
//						num_items++;
					}
					else
					{
						Node* p=new Node;
						p->data=data;
						p->link=curr->link;
						curr->link=p;
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
				if(curr==tail)
				{

					Prev();					
					curr->link=NULL;
					tail=curr;
				//	Prev();
				//	tail=curr;
				//	curr->link=NULL;
					
				}
				else if(curr==head)
				{
					curr=curr->link;
					head=curr;	
				}
				else
				{
					Prev();
					curr->link=curr->link->link;
					Next();
				//	num_items--;
				}
				num_items--;
			}
			if(IsEmpty())
				curr=head=tail=NULL;	
		}
		// replaces the value of the current element with the specified value
		// this should not be possible for an empty list
		void Replace(int data)
		{
			if(!IsEmpty())
			{
				curr->data=data;
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
			return(num_items==MAX_SIZE);
		}

		// returns the concatenation of two lists
		// l should not be modified
		// l should be concatenated to the end of *this
		// the returned list should not exceed MAX_SIZE elements
		// the last element of the new list is the current
		List operator+(const List& l) const
		{
			List ret(*this);
			if(ret.IsEmpty())
			{
				ret=l;
				return ret;
			}
			ret.Last();
			Node* p=l.head;
			while(ret.GetSize()!=MAX_SIZE && p->link!=NULL)
			{
		//	cout << ret << endl;
				ret.InsertAfter(p->data);
				p=p->link;
			}
			return ret;
		}

		// returns if two lists are equal (by value)
		bool operator==(const List& l) const
		{
			if(GetSize()==l.GetSize())
			{
				Node* p=head;
				Node* q=l.head;
				do
				{
					if(p->data!=q->data)
						return false;
					p=p->link;
					q=q->link;
					
				}while(p!=NULL);
				return true;
			}
			return false;
		}

		// returns if two lists are not equal (by value)
		bool operator!=(const List& l) const
		{
			return !(*this==l);
		}

		// returns a string representation of the entire list (e.g., 1 2 3 4 5)
		// the string "NULL" should be returned for an empty list
		friend ostream& operator<<(ostream& out, const List &l)
		{
			if(l.num_items==0)
				out <<"NULL";
			else
			{
				//note this is a helper method, therefore we must ask for the head of a specific list passed in (l)
				Node* p=l.head;
				while(p!=NULL)
				{
					out << p->data << " ";
					p=p->link;	
				}
			}
			return out;

	
		}
};
