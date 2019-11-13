#include "pch.h"
#include<iostream>
using namespace std;
class Node
{

public:
	Node* Left;
	Node* Right;
	int Data;
	void SetData(int d)
	{
		this->Data = d;
	}
	//void SetRight(Node *ptr)
	//{
	//	nxtNode = ptr;

	//}
	//void SetLeft(Node *ptr)
	//{
	//	prevNode = ptr;

	//}
	//int getValue()
	//{
	//	return value;
	//}
	//Node *getNxtNode()
	//{
	//	return nxtNode;
	//}
	//Node *getprevNode()
	//{
	//	return prevNode;
	//}
	void Print()
	{
		cout << "      " << this->Data << endl;
	}
};