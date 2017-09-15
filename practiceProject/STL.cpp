
#include "stdafx.h"
#include <iostream>
#include "Stack.h"
#include "STL.h"

using namespace std;

list<int> gList;
list<int>::iterator lIter;

map <std::string, int> gMap;
map <std::string, int>::iterator MIter;

myStack<int> numStack;

void stl_entry()
{
	/********************
	List practice
	*********************/
	cout << "Hello List!!" << endl;
	gList.push_back(1);
	gList.push_front(2);
	gList.push_back(3);
	gList.push_front(4);
	gList.push_back(5);
	gList.push_front(6);

	cout << "Print list here -> .";
	for (lIter = gList.begin(); lIter != gList.end(); lIter++)
		cout << *lIter << "|";
	cout << endl;
	/********************
	Map practice
	*********************/
	gMap.insert(pair<std::string, int>("nitin", 1));
	gMap.insert(pair<std::string, int>("tina", 2));
	gMap.insert(pair<std::string, int>("advit", 3));

	cout << "Print map here ->";
	std::string name;
	for (MIter = gMap.begin(); MIter != gMap.end(); MIter++)
		cout << (*MIter).first.c_str() << ": " << (*MIter).second << "|";
	cout << endl;

	/********************
	Template practice
	*********************/
	
	for (int i = 0; i < 10;i++)
	{
		numStack.push(i);
		numStack.stackTop();
	}

	for (int i = 0; i < 10;i++)
	{
		numStack.stackTop();
		numStack.pop();
	}

	/*
	Following implementation is not correct.

	Learning:
	Template functions are general and type independent
	but still template funtions expect similar type of data type
	e.g. int, double, float etc and the string, or char*
	*/

	/*
	myStack<char*> strStack;
	char str[5];
	for (int i = 100000000; i < 100000010;i++)
	{
	itoa(i, str, 10);
	strStack.push(str);
	strStack.stackTop();
	}

	for (int i = 0; i < 10;i++)
	{
	strStack.stackTop();
	strStack.pop();
	}
	*/

}