#include "pch.h"
#include<iostream>
#include"Node.cpp"
using namespace std;
class DoubleList
{
	Node* LeftHead;
	Node* RightHead;
	int Count;
public:
	//NULL CONSTRUCTOR
	DoubleList() :LeftHead(NULL), RightHead(NULL), Count(0) {}
	//PARAMETRIC CONSTRUCTOR
	DoubleList(Node* &Ptr) :LeftHead(Ptr), RightHead(Ptr), Count(1)
	{
		RightHead->Left = LeftHead->Right = NULL;
		Ptr = NULL;
	}
	//COPY CONSTRUCTOR
	DoubleList(const DoubleList& Src) :LeftHead(Src.LeftHead), RightHead(RightHead), Count(Src.Count)
	{
		if (Count)
		{
			Node* Sptr, *Dptr;
			LeftHead = Dptr = new Node(*Src.LeftHead);
			Sptr = Src.LeftHead->Right;
			for (int i = 1; i < Count; ++i)
			{
				Dptr->Right=new Node(*Sptr);
				Dptr->Right->Left = Dptr;
				Dptr = Dptr->Right;
				Sptr = Sptr->Right;
			}
			RightHead = Dptr;
		}		
	}
	//GET COUNT
	void GetCount()
	{
		cout << "Count is : " << Count << endl;
	}
	//IS EMPTY
	bool IsEmpty() //to check that stack is empty or not
	{
		cout << "IsEmpty called" << endl;
		if (RightHead || LeftHead)
		{
			cout << "List is not empty" << endl;
			return false;
		}			
		else
		{
			cout << "List is empty" << endl;
			return true;
		}			
	}
	//IS NOT EMPTY
	bool IsNotEmpty() //to check that stack is empty or not
	{
		cout << "IsNotEmpty called" << endl;
		if (RightHead || LeftHead)
		{
			cout << "List is not empty" << endl;
			return true;
		}			
		else
		{
			cout << "List is empty" << endl;
			return false;
		}			
	}
	//PRINT
	void Print()
	{
		cout << "Print of DoubleList" << endl;
		Node* Rptr=LeftHead;
		while(Rptr)
		{
			Rptr->Print();
			Rptr = Rptr->Right;
		}
	}
	//REMOVE AT
	void RemoveAt(Node* &Ptr)//between two nodes
	{
		Ptr->Left->Right = Ptr->Right;
		Ptr->Right->Left = Ptr->Left;
		Ptr->Right = NULL;
		Ptr->Left = NULL;
	}
	//INSERT AT RIGHT----------------------------------------------------------------
	void InsertAtRight(Node* &Ptr,int Index)
	{
		if (!LeftHead)//List Is Empty obvously there is no right head
		{
			LeftHead = RightHead = Ptr;
			LeftHead->Left = RightHead->Right = Ptr;
			++Count;
		}
		else if (Index <= 0)//At Left End -----working
		{
			Ptr->Right = LeftHead;
			LeftHead->Left = Ptr;
			LeftHead = Ptr;
			Ptr = LeftHead->Left = NULL;
			++Count;
		}
		else if (Index >= Count)//At Right End -----working
		{
			Ptr->Left = LeftHead;
			RightHead->Right = Ptr;
			RightHead = Ptr;
			RightHead->Right = Ptr = NULL;
			++Count;
		}
		else//At Right In Between
		{
			Node* Rptr;
			if (Index <= (Count / 2))//Index is in the Left Half
			{
				Rptr = LeftHead;
				for (int i = 1; i < Index; ++i)
				{
					Rptr = Rptr->Right;
				}
			}
			else//Index is in the Right Half
			{
				Rptr = RightHead;
				for (int i = Count; i > Index; --i)
				{
					Rptr = Rptr->Left;
				}
			}
//Logic of Insert at Right
			Ptr->Right = Rptr->Right;
			Ptr->Left = Rptr;
			Rptr->Left = Ptr;
			Ptr->Right->Left = Ptr;
			++Count;
		}
	}
	//INSERT AT LEFT----------------------------------------------------------------
	void InsertAtLeft(Node* &Ptr, int Index)
	{
		if (!LeftHead)//List Is Empty
		{
			LeftHead = RightHead = Ptr;
			LeftHead->Left = RightHead->Right = Ptr;
			++Count;
		}
		else if (Index <= 0)//At Left End
		{
			Ptr->Right = LeftHead;
			LeftHead->Left = Ptr;
			LeftHead = Ptr;
			Ptr = LeftHead->Left = NULL;
			++Count;
		}
		else if (Index >= Count)//At Right End
		{
			Ptr->Left = LeftHead;
			RightHead->Right = Ptr;
			RightHead = Ptr;
			RightHead->Right = Ptr = NULL;
			++Count;
		}
		else//At Left In Between
		{
			Node* Rptr;
			if (Index <= (Count / 2))//Index is in the Left Half
			{
				Rptr = LeftHead;
				for (int i = 1; i < Index; ++i)
				{
					Rptr = Rptr->Right;
				}
			}
			else//Index is in the Right Half
			{
				Rptr = RightHead;
				for (int i = Count; i > Index; --i)
				{
					Rptr = Rptr->Left;
				}
			}
//Logic of Insert at Left
			Ptr->Right = Rptr;
			Ptr->Left = Rptr->Left;
			Rptr->Left = Ptr;
			Ptr->Left->Right = Ptr;
			++Count;
		}
	}
	//DESTRUCTOR
	~DoubleList()
	{
		for (int i = 0; i < Count; ++i)
		{
			RightHead = LeftHead;
			LeftHead = LeftHead->Right;
			delete RightHead;
		}
	}

};//END OF CLASS (***** DoubleList *****)

