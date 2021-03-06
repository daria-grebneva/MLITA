#include "stdafx.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int comp1(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	//ifstream fin("INPUT3.txt");
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	unsigned long long seller, buyer;
	unsigned long long sellerPrices[100000];
	unsigned long long buyerPrices[100000];
	unsigned long long price;

	fin >> seller >> buyer;
	for (unsigned int i = 0; i < seller; i++)
	{
		fin >> sellerPrices[i];
	}
	//sort(begin(sellerPrices), end(sellerPrices));
	qsort(sellerPrices, seller, sizeof(unsigned long long), comp1);
	for (unsigned int i = 0; i < buyer; i++)
	{
		fin >> 	buyerPrices[i];
	}
	//sort(begin(buyerPrices), end(buyerPrices));
	qsort(buyerPrices, buyer, sizeof(unsigned long long), comp1);

	unsigned long long maxCost = 0;
	unsigned long long maxPrice = 0;

	for (unsigned int i = 0; i < buyer; i++)
	{
		unsigned long long readyBuyers = buyer - i;
		unsigned long long j = 0;
		unsigned long long readySellers = 0;
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
