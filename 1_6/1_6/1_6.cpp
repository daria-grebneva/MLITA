//Гребнева Дарья, ПС-21, задача 1.6, среда разработки Visual Studio 2017

/*Имеется N костей игры домино.На каждой кости имеется два числа(каждое от 0 до 6).
Требуется написать программу, которая будет определять максимальное число, составленное из
цифр на костях цепочки, составленной по правилам домино из имеющихся костей.

Ввод.Первая строка входного файла содержит целое число N – количество костей(2  N  20).
Следующие N строк содержат два целых числа X и Y(0  X, Y  6), разделенные пробелом.

Вывод.В выходной файл необходимо вывести максимальное целое число, цифры которого
соответствуют значению костей в цепочке. */

#include "stdafx.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_VALUE = 7;

void rec(string& current, string& answer, vector<vector<int>>& freqs)
{
	if (answer.size() < current.size() || (answer.size() == current.size() && answer < current))
	{
		answer = current;
	}
	if (current.size() == 0)
	{
		for (int i = 0; i < MAX_VALUE; ++i)
		{
			for (int j = 0; j < MAX_VALUE; ++j)
			{
				if (i == 0 && j == 0)
				{
					continue;
				}
				if (freqs[i][j] > 0)
				{
					current.push_back(char(i + '0'));
					current.push_back(char(j + '0'));
					--freqs[i][j];
					--freqs[j][i];
					rec(current, answer, freqs);
					current.pop_back();
					current.pop_back();
					++freqs[i][j];
					++freqs[j][i];
				}
			}
		}
	}
	else
	{
		int digit = current.back() - '0';
		for (int j = 0; j < MAX_VALUE; ++j)
		{
			if (freqs[digit][j] > 0)
			{
				current.push_back(char(digit + '0'));
				current.push_back(char(j + '0'));
				--freqs[digit][j];
				--freqs[j][digit];
				rec(current, answer, freqs);
				current.pop_back();
				current.pop_back();
				++freqs[digit][j];
				++freqs[j][digit];
			}
		}
	}
}

int main()
{

	ifstream fin("input.txt");
	ofstream output("output.txt");

	int n;
	vector<vector<int>> freqs;
	freqs.resize(MAX_VALUE);
	for (int i = 0; i < MAX_VALUE; ++i)
	{
		for (int j = 0; j < MAX_VALUE; ++j)
		{
			freqs[i].push_back(0);
		}
	}
	if (!fin.is_open())
	{
		output << "File cannot be found or opened\n";
		return 1;
	}
	fin >> n;

	if ((n < 2) || (n > 20))
	{
		output << "Your number of dominos must be in the range 2 <= N <= 20\n";
		return 1;
	}

	while (n > 0)
	{
		if (!fin.eof())
		{
			int sum, b;
			fin >> sum >> b;
			if (((sum < 0) || (sum > 6)) || ((b < 0) || (b > 6)))
			{
				output << "Your number of digits of dominos must be 0 <= x <= 6\n";
				return 1;
			}
			++freqs[sum][b];
			++freqs[b][sum];
		}
		else
		{
			break;
		}
		--n;
	}

	if (n > 0)
	{
		output << "Your number of dominos is not equal to the Domino number listed\n";
		return 1;
	}

	string current = "";
	string answer = "";

	rec(current, answer, freqs);

	if (answer.size() == 0)
	{
		answer = "0";
	}
	output << answer << "\n";

	return 0;
}
