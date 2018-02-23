//Гребнева Дарья, ПС-21, задача 1.6, среда разработки Visual Studio 2017

/*Имеется N костей игры домино.На каждой кости имеется два числа(каждое от 0 до 6).
Требуется написать программу, которая будет определять максимальное число, составленное из
цифр на костях цепочки, составленной по правилам домино из имеющихся костей.

Ввод.Первая строка входного файла содержит целое число N – количество костей(2  N  20).
Следующие N строк содержат два целых числа X и Y(0  X, Y  6), разделенные пробелом.

Вывод.В выходной файл необходимо вывести максимальное целое число, цифры которого
соответствуют значению костей в цепочке. */

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Domino
{
	int firstNumber;
	int secondNumber;
	bool isExist = false;
	int next = -1;
	int leftDomino;
	int rightDomino;
};

int N;
int nextParam;
const int MAX_INPUT_DIGIT = 20;
Domino dominosArr[MAX_INPUT_DIGIT];

struct DominosSequence
{
	int sum = -1;
	string str = "";
};

DominosSequence maxSequence;

void FindStringDominos(int first, DominosSequence &maxSequence)
{
	int nextDomino = first;
	int sumDominos = 0;
	string S = "";
		while (nextDomino != -1)
		{
			S = S + to_string(dominosArr[nextDomino].leftDomino) + to_string(dominosArr[nextDomino].rightDomino);
			nextDomino = dominosArr[nextDomino].next;
		}
		if (((S > maxSequence.str) && (S.length() >= (maxSequence.str).length()))
			|| ((S == maxSequence.str) && (S.length() > (maxSequence.str).length())))
		{
			maxSequence.sum = sumDominos;
			maxSequence.str = S;
		}
}

void FindNextDomino(int currentParam, int &right, int &left, int N, int First)
{
	dominosArr[currentParam].rightDomino = right;
	dominosArr[currentParam].leftDomino = left;
	dominosArr[currentParam].isExist = true;
	if (currentParam == (N - 1))
	{
		nextParam = 0;
	}
	else
	{
		nextParam = currentParam + 1;
	}
	while (nextParam != currentParam)
	{
		if (dominosArr[nextParam].isExist == false)
		{
			if (dominosArr[nextParam].firstNumber == dominosArr[currentParam].rightDomino)
			{
				dominosArr[currentParam].next = nextParam;
				FindNextDomino(nextParam, dominosArr[nextParam].secondNumber, dominosArr[nextParam].firstNumber, N, First);
			}
			if ((dominosArr[nextParam].secondNumber == dominosArr[currentParam].rightDomino)
				&& (dominosArr[nextParam].firstNumber != dominosArr[nextParam].secondNumber))
			{
				dominosArr[currentParam].next = nextParam;
				FindNextDomino(nextParam, dominosArr[nextParam].firstNumber, dominosArr[nextParam].secondNumber, N, First);
			}
		}
		nextParam = nextParam + 1;
		if (nextParam > (N - 1))
		{
			nextParam = 0;
		}
	}
	dominosArr[currentParam].next = -1;
	FindStringDominos(First,maxSequence);
	dominosArr[currentParam].isExist = false;
}

void MakeDominosSequence(int N)
{
	int First;
	int currentParam = 0;
	while (currentParam < N)
	{
		First = currentParam;
		if (dominosArr[currentParam].secondNumber != 0)
		{
			FindNextDomino(currentParam, dominosArr[currentParam].firstNumber, dominosArr[currentParam].secondNumber, N, First);
		}
		if ((dominosArr[currentParam].firstNumber != dominosArr[currentParam].secondNumber) && (dominosArr[currentParam].firstNumber != 0))
		{
			FindNextDomino(currentParam, dominosArr[currentParam].secondNumber, dominosArr[currentParam].firstNumber, N, First);
		}
		currentParam = currentParam + 1;
	}
}


int main()
{
	ifstream fin("input.txt");
	ofstream output("output.txt");

	int counterDominos = 0;

	int N = 0;

	if (fin.is_open())
	{

		fin >> N;

		//проверка условия 2 <= N <= 20
		if ((N < 2) || (N > 20))
		{
			output << "Your number of dominos must be in the range 2 <= N <= 20" << endl;
			return 1;
		}

		for (int i = 0; i < N; ++i)
		{
			if (!fin.eof())
			{
				int x;
				int y;
				fin >> x >> y;

				//Проверка вхождения в диапазон от 0 до 6 чисел на домино
				if (((x < 0) || (x > 6)) || ((y < 0) || (y > 6)))
				{
					output << "Your number of digits of dominos must be 0 <= x <= 6" << endl;
					return 1;
				}

				//Добавляем в вектор доминошек все доминошки
				dominosArr[i].firstNumber = x;
				dominosArr[i].secondNumber = y;
				counterDominos++;
			}
		}

		//Если указанное число доминошек не равно числу перечисленных
		if (counterDominos < N)
		{
			output << "Your number of dominos is not equal to the Domino number listed" << endl;
			return 1;
		}
	}
	else
	{
		output << "File cannot be found or opened" << endl;
		return 1;
	}

	string result;

	//Основной цикл
	MakeDominosSequence(N);
	if (maxSequence.sum != -1)
	{
		result = maxSequence.str;
	}
	else
	{
		result =  "0";
	}		

	output << result << endl;

	return 0;
}