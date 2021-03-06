/*Гребнева Дарья, ПС-21, задача 9.2, среда разработки Visual Studio 2017

9.2. Простоватые числа (3)
Студент Вася отыскивает простые числа в диапазоне от 1 до N (1 ≤  N ≤ 10 15 ). Если число M, не
превосходящее N, не делится на 2, 3 и 5, Вася называет его “простоватым”. По заданному
значению N найти количество простоватых чисел.
Ввод. В единственной строке файла INPUT.TXT находится число N.
Вывод. В единственную строку файла OUTPUT.TXT вывести количество простоватых чисел.*/

#include "stdafx.h"

#include <fstream>
#include <iostream>

using namespace std;

const string inputName = "input3.txt";
const string outputName = "output.txt";

int main()
{
	long long N;
	long long counter = 0;
	long long number = 0;

	ifstream fin(inputName);
	ofstream fout(outputName);

	fin >> N;

	if (N >= 30)
	{
		number = N % 30;
		counter = (N / 30) * 8 + number;
	}
	else
	{
		for (int i = 1; i <= N; i += 2)
		{
			if ((i % 3 != 0) && (i % 5 != 0))
			{
				counter++;
			}
		}
	}

	fout << counter << endl;
}
