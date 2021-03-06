#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1e+5;

long long Sum[MAX_N], S[MAX_N], MaxL[MAX_N], MaxR[MAX_N], Max[MAX_N];
int A[MAX_N];

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	unsigned int N, K;
	in >> N >> K;

	for (int i = 0; i < N; i++)
	{
		in >> A[i];
		if (i == 0)
		{
			S[i] = A[i];
		}
		else
		{
			S[i] = S[i - 1] + A[i];
		}
	}

	const unsigned int L = N - K + 1;

	for (int i = 0; i < L; i++)
	{
		Sum[i] = S[i + K - 1] - S[i] + A[i];
	}

	MaxL[0] = Sum[0];
	for (int i = 1; i < L; i++)
	{

		MaxL[i] = max(MaxL[i - 1], Sum[i]);
	}

	MaxR[L - 1] = Sum[L - 1];

	for (int i = L - 2; i >= 0; i--)
	{
		MaxR[i] = max(MaxR[i + 1], Sum[i]);
	}

	for (int i = 0; i < L; i++)
	{
		if (i < K)
		{
			Max[i] = MaxR[i + K];
		}
		else if (i + K >= L)
		{
			Max[i] = MaxL[i - K];
		}
		else
		{
			Max[i] = max(MaxR[i + K], MaxL[i - K]);
		}
	}

	long long ans = Max[0];
	for (int i = 0; i < L; i++)
	{
		if (Max[i] < ans)
		{
			ans = Max[i];
		}
	}

	out << ans << '\n';

	return 0;
}
