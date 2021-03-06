// 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

struct Matrix
{
	int xCoord;
	int yCoord;
	int len;
	int cost = 0;
};
int vectorMatrix[100][100];
const int START_DIG = -1;

vector<Matrix> vecMatrix;
Matrix turtleCoord;

int returnMin(int x, int y)
{
	if (x < y)
	{
		return x;
	}
	else
	{
		return y;
	}

}

int recurs(int x, int y, int n, int m)
{
	
	if ((x == n) && (y == m))
	{
		return vectorMatrix[x][y];
	}
	else
	{
		if (x == n)
		{
			return (recurs(x, y + 1, n, m) + vectorMatrix[x][y]);
		}
		else
		{
			if (y == m)
			{
				return (recurs(x + 1, y, n, m) + vectorMatrix[x][y]);
			}
			else
			{
				return (returnMin(recurs(x + 1, y, n, m), recurs(x, y + 1, n, m)) + vectorMatrix[x][y]);
			}
		}
	}
}

int main()
{
	ifstream fin("input4.txt");
	std::ofstream output("output.txt");
	
	if (fin.is_open()) {
		int a;
		int b;
		fin >> a >> b;
		int x;
		for (int i = a; i >= 1; --i)
		{
			for (int j = b; j >= 1; --j)
			{
				fin >> x;
				vectorMatrix[i][j] = x;
			}
		}
		output << recurs(1, 1, a, b)<< endl;


	}
	else {
		output << "File cannot be found or opened" << endl;
		return 1;
	}
	output << " " << endl;
	return 0;
}
