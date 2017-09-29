#include "stdafx.h"
#include<stdio.h>
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
	rsize = csize = (int)sqrt(msize);

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


/*************************
**************************
SUDOKU: WHAT THE HELL, TOO HARD
**************************
**************************/
int grid[9][9] = {
	{3,0,6, 5,0,8, 4,0,0},
	{5,2,0, 0,0,0, 0,0,0},
	{0,8,7, 0,0,0, 0,3,1},

	{0,0,3, 0,1,0, 0,8,0},
	{9,0,0, 8,6,3, 0,0,5},
	{0,5,0, 0,9,0, 6,0,0},

	{1,3,0, 0,0,0, 2,5,0},
	{0,0,0, 0,0,0, 0,7,4},
	{0,0,5, 2,0,6, 3,0,0}
};

void printGrid(int grid[][9])
{
	for (int r = 0;r < 9;r++)
	{
		if (r % 3 == 0)
			cout << endl << endl;
		for (int c = 0;c < 9;c++)
		{
			if (c % 3 == 0)
				cout << " ";
			cout << grid[r][c] << ", ";
		}
		cout << endl;
	}
}

int sudokuCheck(int rnum, int cnum, int digit)
{
	//column check
	for (int r = 0;r < 9;r++)
		if (digit == grid[r][cnum])
			return 0;
			//bitmask |= (1 << (digit - 1));

	//row check
	for (int c = 0;c < 9;c++)
		if (digit == grid[rnum][c])
			return 0;
			//bitmask |= (1 << (digit - 1));

	//subgrid check
	for (int r = 3 * (rnum / 3); r < ((3 * (rnum / 3)) + 3); r++)
		for (int c = 3 * (cnum / 3); c < ((3 * (cnum / 3)) + 3); c++)
			if (digit == grid[r][c])
				return 0;
				//bitmask |= (1 << (digit - 1));

	//return bitmask;
	return 1;
}

int digits[9] = { 1,2,3,4,5,6,7,8,9 };

#if 0
void sudoku()
{
	int sudComplete = 0;
	int bitmaskgrid[9][9] = { 0 };

	printGrid(grid);

#if 0
	for (int rnum = 0;rnum < 9; rnum += 3)
	{
		for (int cnum = 0; cnum < 9; cnum += 3)
		{
			for (int r = rnum; r < rnum + 3;r++)
				for (int c = cnum;c < cnum + 3;c++)
				{
					if (grid[r][c] > 0)
						digits[grid[r][c] - 1] = 0;
				}

			printf("SubGrid(%d,%d) needs: ", rnum, cnum);
			for (int i = 0;i < 9;i++)
				digits[i] != 0 ? printf("%d ", digits[i]) : i = i;
			printf("\n");
			
			//reset the digits array.
			for (int i = 0; i < 9; i++)
				digits[i] = i + 1;
		}
	}
#endif

	printf("Solved sudoku:\n");

	short bitmask;
	//while (1)
	{
		sudComplete = 1;
		for (int r = 0;r < 9;r++)
			for (int c = 0;c < 9;c++)
			{
				if (grid[r][c] == 0)
				{
					sudComplete = 0;
					short bm = 0;
					for (int d = 1;d <= 9;d++)
						bm = sudokuCheck(bm, r, c, d);
					bitmaskgrid[r][c] = (int)bm ^ 0x1FF;
					/*
					switch (bitmask)
					{
					case 0x0FF: grid[r][c] = 9; break;
					case 0x17F: grid[r][c] = 8; break;
					case 0x1BF: grid[r][c] = 7; break;
					case 0x1DF: grid[r][c] = 6; break;
					case 0x1EF: grid[r][c] = 5; break;
					case 0x1F7: grid[r][c] = 4; break;
					case 0x1FB: grid[r][c] = 3; break;
					case 0x1FD: grid[r][c] = 2; break;
					case 0x1FE: grid[r][c] = 1; break;
					}*/
				}
			}
		//every cell of the grid contains a bitmask whose set bits represent potential numbers for that cell.
		cout << hex;
		printGrid(bitmaskgrid);

		//if (sudComplete)
			//bitmaskgrid[r][break;
	}
	cout << dec;
	printGrid(grid);
}
#endif

//Row major
int nextCell(int *r, int *c)
{
	(*c)++;
	if (*c >=9 )
	{
		(*r)++;
		*c = 0;
	}
	if (*r >= 9)
		return 0;

	return 1;
}

int assignDigitToCell(int grid[][9], int r, int c)
{
	int row = r;
	int col = c;

	if (grid[row][col] != 0)
	{
		if (nextCell(&row, &col))
		{
			if (assignDigitToCell(grid, row, col))
				return 1;
		}
		else
			return 1;
	}
	else
	{
		for (int digit = 1; digit <= 9; digit++)
		{
			/*
			MISTAKE: I was not assigning row = r and col = c before and running into endless issues 
			then relealized that while using recursion and loop together local variables might be required
			to be preserved. Because every time loop runs the next iteration 'nextCell' will increment from
			the next position whereas nextCell should only increment from the original position. 
			*/
			row = r; 
			col = c;
			if (sudokuCheck(row, col, digit))
			{
				grid[row][col] = digit;

				if (nextCell(&row, &col))
				{
					if (assignDigitToCell(grid, row, col))
						return 1;
					else
						grid[r][c] = 0;
				}
				else
					return 1;
			}
		}
	}
	return 0;
}

void sudoku()
{
	printGrid(grid);
	//if (assignDigitToCell(grid, 0, 0))
	assignDigitToCell(grid, 0, 0);
	{
		printf("Sudoku solved: \n");
		printGrid(grid);
	}
}

void rrevString(char* start, char* end)
{
	if (start > end || start - end == 0)
		return;
	else
	{
		char t = *start;
		*start = *end;
		*end = t;

		rrevString(start + 1, end - 1);
	}
}

void reverseString(char* str)
{
	char* s, *e;

	s = str;
	
	while (*str)
		str++;
	
	e = --str;

	rrevString(s, e);
	
	printf("Reversed string: %s\n", s);

}

int factorial(int n)
{
	if (n < 0)
		return n;

	if (n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

int isPalindrome(char* str)
{
	/* TODO for later time , do it usinig recursion */
	return 1;
}

