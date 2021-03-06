/*Гребнева Дарья, ПС-21, задача 8.1, среда разработки Visual Studio 2017

8.1. Слова (3)
Дано слово, состоящее из M (2 ≤ M ≤ 7) строчных букв латинского алфавита. Найти все
перестановки символов данного слова.
Ввод из файла INPUT.TXT. В первой строке файла находится исходное слово.
Вывод в файл OUTPUT.TXT. Вывести в алфавитном порядке без повторений все перестановки
символов данного слова по одной перестановке в каждой строке файла.*/

#include "stdafx.h"

#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

const string inputName = "input.txt";
const string outputName = "output.txt";

void Swap(char& x, char& y)
{
	char s = x;
	x = y;
	y = s;
}

void NextPermutation(size_t pos, string& str, const size_t size, map<string, string>& permutations)
{
	if (pos != size)
	{
		for (size_t i = pos; i < size; i++)
		{
			Swap(str[pos], str[i]);
			NextPermutation(pos + 1, str, size, permutations);
			Swap(str[pos], str[i]);
		}
	}
	else
	{
		permutations.insert(make_pair(str, str));
	}
}

void ReadArr(string& str)
{
	ifstream fin(inputName);

	for (string tmp; fin >> tmp;)
	{
		str.append(tmp);
	}
}

void PrintToFile(map<string, string> permutations)
{
	ofstream fout(outputName);
	for (const auto& s : permutations)
	{
		fout << s.second << endl;
	}
}

int main()
{
	string str;
	ReadArr(str);
	map<string, string> permutations;
	NextPermutation(0, str, str.size(), permutations);
	PrintToFile(permutations);
}
