// Double Link List Theory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include"Double List.cpp"
using namespace std;
int main()
{	//NODES
	Node *Ptr1 = new Node();
	Ptr1->SetData(10);
	Node *Ptr2 = new Node();
	Ptr2->SetData(20);
	Node *Ptr3 = new Node();
	Ptr3->SetData(30);
	Node *Ptr4 = new Node();
	Ptr4->SetData(40);
	Node *Ptr5 = new Node();
	Ptr5->SetData(50);
	Node *Ptr6 = new Node();
	Ptr6->SetData(60);
	Node *Ptr7 = new Node();
	Ptr7->SetData(70);
	Node *Ptr8 = new Node();
	Ptr8->SetData(80);
	//OBJECT 1
	DoubleList D1(Ptr1);
	D1.IsEmpty();
	D1.Print();
	/*cout << "Checking RemoveAt : " << endl;
	D1.RemoveAt(Ptr1);
	D1.IsEmpty();
	D1.Print();*/

	//LEFT // not working for 3,
	cout << "Checking InsertAtLeft : " << endl;
	D1.InsertAtLeft(Ptr2, 0);//
	D1.Print();
	cout << "Checking InsertAtLeft : " << endl;
	D1.InsertAtLeft(Ptr3, 0);
	D1.Print();
	cout << "Checking InsertAtLeft : " << endl;
	D1.InsertAtLeft(Ptr4, 0);// (not) working for 3 because it gets the case of index >= count
	D1.Print();
	cout << "Checking InsertAtLeft : " << endl;
	D1.InsertAtLeft(Ptr5, 0);
	D1.Print();
	//RIGHT
	cout << "Checking InsertAtRight : " << endl;
	D1.InsertAtRight(Ptr6, 4);//At index 5 or to the right of 5th position
	D1.Print();
	//cout << "Checking InsertAtRight : " << endl;
	//D1.InsertAtRight(Ptr7, 7/8);//right most
	//D1.Print();
	//cout << "Checking InsertAtRight : " << endl;
	//D1.InsertAtRight(Ptr8, -1);//left most
	//D1.Print();
	//COUNT
	cout << "Checking GetCount : " << endl;
	D1.GetCount();
	//cout << "Checking CopyConstructor : " << endl;
	//COPY CONSTRUCTOR
	//DoubleList D2(D1);
	//D2.Print();
	system("PAUSE");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
