#include "stdafx.h"

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	ifstream fin("in5.txt");
	int N;
	int xA, yA;
	int xB, yB;
	int xC, yC;
	fin >> N;
	fin >> xA >> yA;
	fin >> xB >> yB;

	int counter = 0;

	while (!fin.eof())
	{
		fin >> xC >> yC;

		if (((xB - xA) * (yC - yB) - (yB - yA) * (xC - xB)) > 0)
		{
			counter++;
		}
		xA = xB;
		yA = yB;
		xB = xC;
		yB = yC;
	}

	cout << counter << endl;

	return 0;
}
