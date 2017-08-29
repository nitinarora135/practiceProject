// projectHash.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <map>
using namespace std;

list <int> gList;
list<int>::iterator lIter;

std::map <std::string, int> gMap;
std::map <std::string, int>::iterator MIter;

template <class T> class myStack {
private:
	T stack[10];
	int top = -1;

public:
	int push(T ele);
	int pop();
	void stackTop() { cout << "Stack top:" << stack[top] << endl; }
};

template <class T> int myStack<T>::push(T ele)
{
	if (top >= 9)
	{
		cout << "ERROR:  stack is full";
		return -1;
	}
	stack[++top] = ele;
	return 0;
}

template <class T> int myStack<T>::pop()
{
	if (top == -1)
	{
		cout << "Stack is empty";
		return -1;
	}
	top--;
	return 0;
}

int main()
{
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

	gMap.insert(pair<std::string, int>("nitin", 1));
	gMap.insert(pair<std::string, int>("tina", 2));
	gMap.insert(pair<std::string, int>("advit", 3));

	cout << "Print map here ->";
	std::string name;
	for (MIter = gMap.begin(); MIter != gMap.end(); MIter++)
		cout << (*MIter).first.c_str() << ": " << (*MIter).second << "|";
	cout << endl;

	myStack<int> numStack;
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


	getchar();
	return 0;
}

