#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;

const string inputFileName = "input4.txt";
const int SIZE = 6;

bool visited[SIZE][SIZE];

int maxCount = 0;

void Metka(int i, int j, int& count, char graph[SIZE][SIZE])
{
	if (visited[i][j])
	{
		count++;
		if (maxCount < count)
		{
			maxCount = count;
		}
		visited[i][j] = false;
		Metka(i + 1, j, count, graph);
		Metka(i - 1, j, count, graph);
		Metka(i, j + 1, count, graph);
		Metka(i, j - 1, count, graph);

		count--;
		visited[i][j] = true;
	}
}

int main()
{
	ifstream fin(inputFileName);
	int n, m;
	fin >> n >> m;

	char graph[SIZE][SIZE];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			fin >> graph[i][j];
			if (graph[i][j] == '#')
			{
				visited[i][j] = true;
			}
			else
			{
				visited[i][j] = false;
			}
		}
	}

	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (graph[i][j] == '#')
			{
				Metka(i, j, count, graph);
			}
		}
	}
	cout << maxCount << endl;
	return 0;
}
