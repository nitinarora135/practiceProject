#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "BinaryTree.h"
#include "STL.h"
#include "AdhocPracticeHere.h"

using namespace std;

int main()
{
	char choice;
	cout << "**********************" << endl;
	cout << "Practice Project menu" << endl;
	cout << "**********************" << endl;
	cout << "1. Standard Template Library (Press 's')" << endl;
	cout << "2. Binary Tree               (Press 'b')" << endl;
	cout << "3. Practice program          (Press 'p')" << endl;

	char str[64] = "My name is nitin";

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
	// 'p' stands for ad-hoc practice programs
	case 'p':
		sumofbitdifference();
		effSumBitDiff();
		power(3, 5);
		//rotateMatrix();
		writenuminpoweroftwo(-76);
		resetthesignbit(-76);

		rotatewoutxtraspace();
		sudoku();
		reverseString(str);
		cout << "Factorial:" << factorial(3);
		break;
	default:
		cout << "no choice" << endl;
	}

	getchar();
}