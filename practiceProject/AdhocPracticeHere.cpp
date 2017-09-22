#include "stdafx.h"
#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

int arr[5] = { 1, 3, 5, 6, 8};

int numofbits(int num)
{
	int count = 0;

	while (num != 0)
	{
		count += num & 0x01;
		num >>= 1;
	}
	return count;
}

void sumofbitdifference()
{
	int num=0, bitcount=0;
	int SIZE = sizeof arr / sizeof arr[0];

	for (int i = 0;i < SIZE; i++)
	{
		for (int j = i+1; j < SIZE;j++)
		{
			num = arr[i] ^ arr[j];
			bitcount += numofbits(num);
		}
	}
	bitcount *= 2;

	cout << "sum of bit difference :" << bitcount << endl;
}

void effSumBitDiff()
{
	int count = 0;
	int sumOfbitdiff = 0;
	int size = sizeof arr / sizeof arr[0];

	for (int i = 0;i < 32;i++)
	{
		count = 0;

		for (int j = 0;j < size; j++)
			if (arr[j] & (1 << i))
				count++;
		sumOfbitdiff += (count * (size -count) * 2);
	}

	cout << "eff sum of bit diff: " << sumOfbitdiff << endl;
}

long long power(int x, int y)
{
	long long ans = 1;
	long long ir = 0;

	int x2 = x;
	for (int i = 0; i < 32;i++)
	{
		if(i)
			x *= x;
		if (y&(1 << i))
		{
			ans *= x;
			cout << "ans:" << ans << endl;
		}
	}
	cout << "Ans by shifing:" << ans << endl;

	ans = 1;
	for (int i = 0;i < y;i++)
		ans *= x2;
	return ans;
}


/*****************************************************
Inplace rotation of Square matrix without extra space.
******************************************************/

#define RSIZE 5
#define CSIZE 5

int matrix[RSIZE][CSIZE] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };

void printMat()
{
	/* Print row major */
	for (int i = 0; i < RSIZE; i++)
	{
		for (int j = 0; j < CSIZE;j++)
			cout << dec << matrix[i][j] << ",";
		cout << endl;
	}
}

void rotateMatrix()
{
	printMat();
	int numele = sizeof matrix / sizeof matrix[0][0];
	int rsize = 4;
	int csize = 4;
	
	cout << "Now rotate the matrix" << endl;
	queue <int> bdata;

	for (int i = rsize-1; i >= 0; i--)
	{
		for (int j = 0; j < csize; j++)
		{
			bdata.push(matrix[j][i]);
		}
	}
	for (int i = 0;i < rsize;i++)
		for (int j = 0;j < csize;j++)
		{
			matrix[i][j] = bdata.front();
			bdata.pop();
		}

	//for(int i=0;i<)
	printMat();
}
void rotateonce(int max, int min)
{
	int tmp;

	tmp = matrix[min][max];

	//Shift upward the right most column
	for (int j = min;j < max;j++)
		matrix[j][max] = matrix[j + 1][max];

	//Shift bottom row to the right
	for (int j = max;j > min;j--)
		matrix[max][j] = matrix[max][j - 1];

	//Shift left column downward
	for (int j = max; j > min;j--)
		matrix[j][min] = matrix[j - 1][min];

	//Shift top row leftward
	for (int j = min; j < max - 1; j++)
		matrix[min][j] = matrix[min][j + 1];

	matrix[min][max - 1] = tmp;
}

void rotatewoutxtraspace()
{
	printMat();
	cout << "Now rotate the matrix and print again:" << endl;
	int msize = sizeof matrix / sizeof matrix[0][0];
	int rsize, csize;
	rsize = csize = sqrt(msize);

	int max = rsize - 1;
	int min = 0;

	while (max > min || max != min)
	{
		for (int i = 0;i < max - min;i++)
			rotateonce(max, min);
		max--;
		min++;
	}


	printMat();
}




/************************************************************
Understanding computer arithmetic
*************************************************************/
char bits[64] = { 0 };

void writenuminpoweroftwo(int n)
{
	int bitpos = 0;
	cout << endl << "Write number in octal and hex: (dec)-> " << n << " , (oct)->" << oct << n << " , (hex)->" << hex << n;

	cout << endl << "Write number in power of 2 :" << endl;

	cout << n << " = ";
	int bn = n;

	if (n > 0)
		while (n)
		{
			if (n & 1)
			{
				cout << "2^" << bitpos;
				n == 1 ? cout << " ; " : cout << " + ";
			}
			n >>= 1;
			bitpos++;
		}
	else
		cout << "******* HOW TO WRITE -ve NUMBERS IN POWERS OF 2 POLYNOMIAL ********" << endl;

	cout << endl << "Write number in binary :" << endl;
	cout << bn << " = ";
	bitpos = 0;
	//while(bn)
	for(int i=0;i<(sizeof bn) * 8; i++)
	{
		(bn & 1) ? bits[bitpos++] = '1' : bits[bitpos++] = '0';
		bn >>= 1;
	}
	
	cout << dec << "bitpos:" << bitpos << endl;
	for (int i = bitpos; i > 0; i--)
	{
		cout << bits[i - 1];
		if ((i-1) % 4 == 0)
			cout << " ";
	}

	cout << endl;
}

void resetthesignbit(int signedvar)
{
	int sz = sizeof signedvar;
	sz = sz * 8;

	cout << dec << "original var:" << signedvar << endl;

	cout << "Take a 'short', add to it's complement and typecast to integer:" << endl;
	short var = -
		0x7f;
	int result = 0;
	result = var + ~var; // should give -1 for all non-negative var
	cout << dec << "result:" << result << endl;
	
	cout << hex << "var:" << var << "(int)var:" << (int)var << endl;

	cout << "-ve zero:" << -0 << endl;
}


