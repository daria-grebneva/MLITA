//Гребнева Дарья, ПС-21, задача ремонт дорог
//среда разработки Visual Studio 2017
#include "stdafx.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

unsigned long long N;
unsigned int M;

unsigned long long depth = 0;
unsigned long long sector = 0;
unsigned long long a, b;

struct dotInfo
{
	long long coord = 0;
	long long bracketNum = 0;
	char bracketType = ' ';
};

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	fin >> N >> M;

	unsigned long long iter = 1;
	vector<dotInfo> vectorDots;
	for (unsigned long long i = 0; i < N; i++)
	{
		fin >> a >> b;
		dotInfo currDot;
		currDot.coord = a;
		currDot.bracketNum = iter;
		currDot.bracketType = 'L';
		vectorDots.push_back(currDot);
		currDot.coord = b;
		currDot.bracketNum = iter;
		currDot.bracketType = 'R';
		vectorDots.push_back(currDot);
		iter++;
	}

	//сортировка вектора
	sort(vectorDots.begin(), vectorDots.end(),
		[](const dotInfo& a, const dotInfo& b) -> bool {
			return ((a.coord == b.coord) && (a.bracketType != 'R')) || a.coord < b.coord;
		});

	long long left = 0;
	long long right = 0;
	for (auto& currDot : vectorDots)
	{
		switch (currDot.bracketType)
		{
		case 'L':

			depth++;
			if (depth == M)
			{
				left = currDot.coord;
			}
			break;
		case 'R':
			depth--;
			if (depth == M - 1)
			{
				right = currDot.coord;
				if (right - left > 0)
				{
					sector++;
				}
			}
			break;
		default:
			break;
		}
	}

	fout << sector << endl;

	return 0;
}
