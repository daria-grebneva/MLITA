//Гребнева Дарья, ПС-21, задача с практики №9, среда разработки Visual Studio 2017
#include "stdafx.h"

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

const string inputFileName = "input5.txt";
const string outputFileName = "output.txt";

vector<vector<int>> InitializeVector(int K, ifstream& fin)
{
	vector<vector<int>> records;
	for (int row = 1; row <= K; row++)
	{
		int predecessorsNum;
		fin >> predecessorsNum;
		vector<int> rowStr;
		for (int col = 1; col <= K; col++)
		{
			rowStr.push_back(0);
		}
		for (int j = 0; j < predecessorsNum; j++)
		{
			int pos;
			fin >> pos;
			rowStr[pos - 1] = 1;
		}
		records.push_back(rowStr);
	}
	return records;
}

void PrintVector(const vector<vector<int>>& records)
{
	for (auto& row : records)
	{
		for (auto& col : row)
		{
			cout << col;
		}
		cout << endl;
	}
}

bool ChangeVectorValue(vector<vector<int>>& records, vector<int>& zeroRecords)
{
	bool isReplace = false;
	for (int row = 0; row < records.size(); row++)
	{
		if (find(zeroRecords.begin(), zeroRecords.end(), row) != zeroRecords.end())
		{
			continue;
		}
		if (find(records[row].begin(), records[row].end(), 1) != records[row].end())
		{
		}
		else
		{
			zeroRecords.push_back(row);
			isReplace = true;
		}

		for (int col = 0; col < records.size(); col++)
		{
			if (records[row][col] == 1)
			{
				if (find(zeroRecords.begin(), zeroRecords.end(), col) != zeroRecords.end())
				{
					isReplace = true;
					records[row][col] = 0;
					if ((find(records[row].begin(), records[row].end(), 1) != records[row].end()))
					{
					}
					else
					{
						zeroRecords.push_back(row);
					}
				}
			}
		}
	}
	return isReplace;
}

int main()
{
	ifstream fin(inputFileName);
	ofstream fout(outputFileName);

	int K;
	fin >> K;
	vector<vector<int>> records = InitializeVector(K, fin);
	vector<int> order;
	while (ChangeVectorValue(records, order))
		;

	if (order.size() == K)
	{
		fout << "YES" << endl;
		for (auto& zer : order)
		{
			fout << zer + 1 << endl;
		}
	}
	else
	{
		fout << "NO" << endl;
	}

	return 0;
}
