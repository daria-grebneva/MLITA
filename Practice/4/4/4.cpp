// 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <fstream>
#include <iostream>
#include <string>;

using namespace std;

bool IsEqual(string f, string s)
{
	if (f.length() == s.length())
	{
		return true;
	}
	else
	{
		return false;
	}
}

string DelZero(string f)
{
	string newF = "";
	bool meetNotZero = false;
	int i = 0;
	while (i < f.length())
	{
		if (!meetNotZero)
		{
			if (f[i] != '0')
			{
				meetNotZero = true;
			}
			else
			{
				while (f[i] == '0')
				{
					i++;
				}
			}
		}
		newF += f[i];
		i++;
	}
	return newF;
}

int main()
{
	ifstream fin("input10.txt");
	ofstream output("output.txt");

	string subtrahend;
	string subtractor;
	fin >> subtrahend >> subtractor;
	string diff;
	string newD;
	int lenF = subtrahend.length();
	int lenS = subtractor.length();
	int dif = lenF - lenS;

	int j = lenS;
	bool isFirstCycle = true;
	for (int i = lenF; i >= dif; --i)
	{
		if (!isFirstCycle)
		{
			if (subtrahend[i] >= subtractor[j])
			{
				int sub = subtrahend[i] - subtractor[j];
				newD += to_string(sub);
				isFirstCycle = false;
			}
			else
			{
				int sub = 10 + subtrahend[i] - subtractor[j];
				if (subtrahend[i - 1] != '0')
				{
					subtrahend[i - 1] = subtrahend[i - 1] - 1;
					newD += to_string(sub);
				}
				else
				{
					int k = 1;
					while (subtrahend[i - k] == '0')
					{
						subtrahend[i - k] = '9';
						k++;
					}
					subtrahend[i - k] = subtrahend[i - k] - 1;
					newD += to_string(sub);
				}
			}
		}

		isFirstCycle = false;
		j--;
	}
	for (int i = lenF - newD.length() - 1; i >= 0; --i)
	{
		diff += subtrahend[i];
	}
	reverse(newD.begin(), newD.end());
	reverse(diff.begin(), diff.end());
	diff += newD;
	diff = DelZero(diff);
	output << diff << endl;
	return 0;
}
