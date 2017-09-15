#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "BinaryTree.h"
#include "STL.h"

using namespace std;

int main()
{
	char choice;
	cout << "**********************" << endl;
	cout << "Practice Project menu" << endl;
	cout << "**********************" << endl;
	cout << "1. Standard Template Library (Press 's')" << endl;
	cout << "2. Binary Tree               (Press 'b')" << endl;


	choice = getchar();
	system("cls");
	switch (choice)
	{
	case 's':
		stl_entry();
		break;

	case 'b':
		binaryTree();
		break;
	default:
		cout << "no choice" << endl;
	}

	getchar();
}