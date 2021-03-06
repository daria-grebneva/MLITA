#include "stdafx.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
unsigned long long sellerPrices[100000];
unsigned long long buyerPrices[100000];

int comp1(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	ifstream fin("input10.txt");
	ofstream fout("output.txt");

	unsigned long long seller, buyer;
	unsigned long long price;
	if (!fin.is_open())
	{
		fout << "File cannot be found or opened\n";
		return 1;
	}
	fin >> seller >> buyer;
	for (unsigned int i = 0; i < seller; i++)
	{
		fin >> sellerPrices[i];
	}
	qsort(sellerPrices, seller, sizeof(unsigned long long), comp1);
	for (unsigned int i = 0; i < buyer; i++)
	{
		fin >> buyerPrices[i];
	}
	qsort(buyerPrices, buyer, sizeof(unsigned long long), comp1);

	unsigned long long maxCost = 0;
	unsigned long long maxPrice = 0;


	unsigned long long readySellers = 0;
	for (unsigned int i = 0; i < buyer; i++)
	{
		unsigned long long readyBuyers = buyer - i;
		unsigned long long j = readySellers;
		while (buyerPrices[i] >= sellerPrices[j])
		{
			readySellers++;
			j++;
		}
		if (maxCost < (min(readySellers, readyBuyers) * buyerPrices[i]))
		{
			maxCost = min(readySellers, readyBuyers) * buyerPrices[i];
			maxPrice = buyerPrices[i];
		}

	}
	fout << maxPrice << "  " << maxCost << endl;

	return 0;
}
