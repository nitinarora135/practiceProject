#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "BinaryTree.h"
#include "STL.h"
#include "AdhocPracticeHere.h"
#include "PermComb.h"

using namespace std;

char dict[10][20] = { "ale", "abc", "kale", "cfg", "jfkjuiekfjfjd", "jfkdjfd",
					"apple", "app", "kaju", "zatu" };

int trip[] = { 0 };

int findMax[10] = { 3,5,6,2,10,1,35, 24,23,46 };
char buf[3] = { 0 };

int main()
{
	char choice;
	cout << "**********************" << endl;
	cout << "Practice Project menu" << endl;
	cout << "**********************" << endl;
	cout << "1. Standard Template Library (Press 's')" << endl;
	cout << "2. Binary Tree               (Press 'b')" << endl;
	cout << "3. Permutation Combination   (Press 'p')" << endl;
	cout << "4. Adhoc practice            (Press 'a')" << endl;

	char str[64] = "My name is nitin";
	char s1[32] = "my name is nitin xyz";
	char s2[32] = "my name ns iitin";
	int cnt=0;

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
	case 'p':
		//cout << "Permutation with Repitattion (A,B,C): " << permWithRepsR(buf, 3, 3, 0) << endl;
		//cout << "Permutation without Repitation (n!) : " << permWoutRepsR(buf, 3, 3, 0) << endl;
		cout << "Print all subsets of a given set (A,B,C) : " << printAllSubsets(buf, 3, 0, 0) << endl;
		break;
	// 'p' stands for ad-hoc practice programs
	case 'a':
		sumofbitdifference();
		effSumBitDiff();
		power(3, 5);
		//rotateMatrix();
		writenuminpoweroftwo(-76);
		resetthesignbit(-76);

		rotatewoutxtraspace();
		//sudoku();
		largestWordInDict(dict, "aepeple");

		fillSlot(4, 0, 0, 'a', &cnt);
		cout << "Total permutations of string with Constraints: " << cnt;
		reverseString(str);
		permutation("abcd");
		//triplets_n3(numbers, 10);
		//all_triplets(numbers, 10);
		cout << "Recursive max: " << recMax(findMax, 10);
		cout << "Total number of triplets: " << ncr_rec(trip, 4, 2);
		cout << "Factorial:" << factorial(3);
		cout << "Is Meta String [" << s1 << "," << s2 << "]" << ((isMetaStr(s1, s2) == 1) ? "Yes" : "No") << endl;
		break;
	default:
		cout << "no choice" << endl;
	}

	getchar();
}