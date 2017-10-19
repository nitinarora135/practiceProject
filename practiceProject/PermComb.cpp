#include <stdafx.h>
#include <iostream>
#include "PermComb.h"

using namespace std;

char dataset[3] = { 'A', 'B', 'C' };
#define DATASIZE (sizeof(dataset)/sizeof(dataset[0])) 

/***********************************
********** Recursive Section *******
***********************************/
/*
        
                        < >
  _
  |			    /        |        \
  |		      <a>        <b>      <c>
  r		   /  |  \     /  |  \   /  |  \
  |	     aa  ab  ac  ba   bb bc ca  cb  cc
  |
  _		 and so on.
		
		
		|--------------- n ----------------|
		

		r is the length of the words formed
		n is the length of the set or array


		My opinion:
		With repitions r could be a bigger number than n
		Without repition r should be smaller.
*/

//equivalent to k^n, where n slots to be filled by a set of size k
int permWithRepsR(char buf[], int r, int n, int ri)
{
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		buf[ri] = dataset[i];

		if (ri < r-1)
			count += permWithRepsR(buf, r, n, ri + 1);
		else
		{
			printf("{");
			for (int j = 0;j < r;j++)
				printf("%c,", buf[j]);
			printf("}\n");
			count++;
		}
	}
	return count;
}

int isDuplicate(char ch, char buf[], int sz)
{
	for (int i = 0;i < sz;i++)
		if (ch == buf[i])
			return 1;

	return 0;
}
//equivalent to factorial i.e. n!
int permWoutRepsR(char buf[], int r, int n, int ri)
{
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		// Following isDuplicate check helps Prune the tree which was 
		// created in earlier function (Perm with repitition).
		if (isDuplicate(dataset[i], buf, ri))
			continue;

		buf[ri] = dataset[i];

		if (ri < r - 1)
			count += permWoutRepsR(buf, r, n, ri + 1);
		else
		{
			printf("{");
			for (int j = 0; j < r; j++)
				printf("%c,", buf[j]);
			printf("}\n");
			count++;
		}
	}
	return count;
}

int permWithConstraints(char buf[], int sz, int n, int r)
{
	return 1;
}

int Combinations(char buf[], int sz, int n, int r)
{
	return 1;
}

void printBuf(char buf[], int sz)
{
	cout << "{";
	for (int i = 0; i < sz;i++)
	{
		if(buf[i] != 0)
			cout << buf[i] << ", ";
	}
	cout << "}" << endl;
} 

int printAllSubsets(char buf[], int sz, int ni, int ri)
{
	int count = 0;
	for (int i = ni; i < sz; i++)
	{

		if (isDuplicate(dataset[i], buf, sz))
			continue;

		buf[ri] = dataset[i];

		printBuf(buf, sz);
		count++;

		if (ri < sz - 1)
			count +=printAllSubsets(buf, sz, ni + 1, ri + 1);
		
		buf[ri] = 0;
	}
	return count;
}