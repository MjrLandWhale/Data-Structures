/****************************************************
 * <Mitchell Brandone>
 * <September 21st 2015>
 * <EasyList.cc>
 *
 * <a simple, short program/class description>
 ****************************************************/

#include <iostream>
using namespace std;


const int MAX_SIZE = 30;

class List
{
	private:
		int end;		// the index of the last valid item in the list
		int curr;		// the index of the current item in the list
		int list[MAX_SIZE];	// the list

	public:
		// constructor
		// remember that an empty list has a "size" of -1 and its "position" is at -1
		List()
		{
			end=-1;
			curr=-1;
			//You dont need to worry about "zeroing out" values left in list
		}

		// copy constructor
		// clones the list l and sets the last element as the current
		List(const List& l)
		{
			*this=l;
		}

		// copy constructor
		// clones the list l and sets the last element as the current
		void operator=(const List& l)
		{
			end=curr=-1;
                        for(int i=0;i<l.GetSize();i++)
                        {
                                InsertAfter(l.list[i]);
                        }
		}

		// navigates to the beginning of the list
		void First()
		{
			if(curr>0)
				curr=0;
		}

		// navigates to the end of the list
		// the end of the list is at the last valid item in the list
		// this should not be possible for an empty list (although maybe it doesn't matter?)
		void Last()
		{
			curr=end;
		}

		// navigates to the specified element (0-index)
		// this should not be possible for an empty list
		// this should not be possible for invalid positions
		void SetPos(int pos)
		{
			if(pos >=0 &&pos <= end && !IsEmpty())
				curr=pos;
		}

		// navigates to the previous element
		// this should not be possible for an empty list
		// there should be no wrap-around
		void Prev()
		{
			if(GetPos()>0)
				curr--;
		}

		// navigates to the next element
		// this should not be possible for an empty list
		// there should be no wrap-around
		void Next()
		{
			if(!IsEmpty() && GetPos()!=end)
				curr++;
		}

		// returns the location of the current element (or -1)
		int GetPos()
		{
			return curr;
		}

		// returns the value of the current element (or -1)
		int GetValue()
		{
			if(IsEmpty())
				return -1;
			else
				return list[curr];
		}

		// returns the size of the list
		// size does not imply capacity
		int GetSize() const
		{
			return (end+1);
		}

		// inserts an item before the current element
		// the new element becomes the current
		// this should not be possible for a full list
		void InsertBefore(int data)
		{
			if(IsFull())
				return;
			if(IsEmpty())
			{
				curr++;
			}
			for(int i=end;i>=curr;i--)
                        {
                       		list[i+1]=list[i];
                        }
			end++;
			list[curr]=data;	
		}

		// inserts an item after the current element
		// the new element becomes the current
		// this should not be possible for a full list
		void InsertAfter(int data)
		{	
			if(IsFull())
				return;
			if(IsEmpty())
			{
				list[0]=data;
				curr++;
				end++;
			}
			else
			{
				curr++;	
				InsertBefore(data);
			}
		}

		// removes the current element (collapsing the list)
		// this should not be possible for an empty list
		void Remove()
		{
			if(IsEmpty())
				return;
			if(curr==end)
			{
				curr--;
			}
			else
			{
				for(int i=GetPos();i<end;i++)
				{
					list[i]=list[i+1];
				}
			}
			end--;
		}

		// replaces the value of the current element with the specified value
		// this should not be possible for an empty list
		void Replace(int data)
		{
			if(!IsEmpty())
				list[GetPos()]=data;
		}

		// returns if the list is empty
		bool IsEmpty() const
		{
			return (end==-1);
		}

		// returns if the list is full
		bool IsFull()
		{
			return (MAX_SIZE==GetSize());
		}

		// returns the concatenation of two lists
		// l should not be modified
		// l should be concatenated to the end of *this
		// the returned list should not exceed MAX_SIZE elements
		// the last element of the new list is the current
		List operator+(const List& l) const
		{
			List retList=*this;
			retList.Last();
			for(int i=0;i<l.GetSize();i++)
			{
				retList.InsertAfter(l.list[i]);
			}
			return retList;
		}

		// returns if two lists are equal (by value)
		bool operator==(const List& l) const
		{	if(GetSize()!=l.GetSize())
				return false;
			for(int i=0;i<GetSize();i++)
			{
				if(list[i]!=l.list[i])
					return false;
			}
			return true;
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
			if(l.IsEmpty())
				out << "NULL";
			else
			{
				for(int i=0;i<l.GetSize();i++)
				{
					out << l.list[i] << " ";
				}
			}
			return out;
		}
};
