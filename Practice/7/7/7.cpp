/*
Гребнева Дарья, ПС-21, задача по практике, среда разработки Visual Studio 2017

Необходимо изменить значение следующих констант для тестирования:
const int ARR_SIZE - размерность входной последовательности 
const string inputName - имя входного файла, в котором содержится последовательность

*/

#include "stdafx.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

const int ARR_SIZE = 3; //Изменить!
const string inputName = "in1.txt"; //Изменить!

int arrNum[ARR_SIZE];

void ReadArr()
{
	int i = 0;
	ifstream fin(inputName);
	while (!fin.eof())
	{
		fin >> arrNum[i];
		i++;
	}
}

int FindTransposeCoord()
{
	int prevCoord = 0;
	int prevNum = 0;
	for (int i = ARR_SIZE - 1; i >= 0; i--)
	{
		if (prevNum > arrNum[i])
		{
			return prevCoord;
		}
		prevNum = arrNum[i];
		prevCoord = i;
	}
	return 0;
}

int FindMin(int prevCoord)
{
	int prevNum = arrNum[prevCoord];
	int minFromMax = ARR_SIZE;
	int minFromMaxCoord = 0;
	if (prevCoord + 1 < ARR_SIZE)
	{
		for (int i = prevCoord + 1; i < ARR_SIZE; i++)
		{
			if (arrNum[i] > prevNum)
			{
				if (minFromMax > arrNum[i])
				{
					minFromMax = arrNum[i];
					minFromMaxCoord = i;
				}
			}
		}
	}
	return minFromMaxCoord;
}

void PrintNewTransposition()
{
	for (int n = 0; n < ARR_SIZE; n++)
	{
		cout << arrNum[n];
	}
	cout << endl;
}

void Reverce(int midCoord)
{
	string s = "";
	for (int i = midCoord; i < ARR_SIZE; i++)
	{
		s += arrNum[i];
	}
	reverse(begin(s), end(s));
	int n = 0;
	for (int i = midCoord; i < ARR_SIZE; i++)
	{
		arrNum[i] = s[n];
		n++;
	}
}

int main()
{
	ReadArr();
	PrintNewTransposition();
	bool needTranspose = true;
	int countArrs = 0;
	while ((needTranspose) && (countArrs < 5))
	{
		int midCoord = FindTransposeCoord();
		if (midCoord != 0)
		{
			int prevCoord = midCoord - 1;
			int exchangeCoord = FindMin(prevCoord);
			if (exchangeCoord == 0)
			{
				swap(arrNum[midCoord], arrNum[midCoord - 1]);
				Reverce(midCoord);
			}
			else
			{
				swap(arrNum[prevCoord], arrNum[exchangeCoord]);
				Reverce(midCoord);
			}
			PrintNewTransposition();
			countArrs++;
		}
		else
		{
			needTranspose = false;
		}
	}

	return 0;
}
