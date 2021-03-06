#include "stdafx.h"

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


const int N = 49;
//const int N = 49995;
//const int N = 99999;
int arrSquare[N + 1];

bool IsSquare(int N)
{
	if (sqrt(N) - (int)sqrt(N) < 0.001)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int returnSquare(int N)
{
	return N * N;
}

void CreateSquareArr(int N)
{
	for (int i = 1; i <= N; ++i)
	{
		int j = 1;
		while (j * j <= i)
		{
			arrSquare[i] = 1 + arrSquare[i - j * j];
			++j;
		}
	}
}

int FindSquare(int N)
{
	int min = N;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (j * j <= i)
			{
				int newS = 1 + arrSquare[N - j * j];
				if (min > newS)
				{
					min = newS;
				}
			}
		}
	}
	return min;
}

int main()
{
	CreateSquareArr(N);
	cout << FindSquare(N) << endl;
    return 0;
}

