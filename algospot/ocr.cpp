#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <math.h>

using namespace std;

typedef double FP;

int m, q;
vector<vector<FP>> M, T;
vector<FP> B;

FP cache[501][101];

FP search(int prev, int remain)
{
	FP& ret = cache[prev][remain];
	if (ret < 1.0)
		return ret;	

	if (remain == 0)
	{
	}

	for (int i = 0; i < m; i++)
	{
		if (remain == 
		max()
	}

	return ret;
}

int main()
{
#if _DEBUG
	FILE* pIn = fopen("ocr.in", "r+");
#else
	FILE* pIn = stdin;
#endif

	char ss[11];
	FP dd;

	fscanf(pIn, "%d%d", &m, &q); 

	vector<string> R(q);
	for (auto& r : R)
	{
		fscanf(pIn, "%s", ss);
		r = string(ss);
	}

	B = vector<FP>(m);
	for (int c = 0; c < m; c++)
	{
		fscanf(pIn, "%lf", &dd);
		B[c] = log10(dd);
	}

	M = vector<vector<FP>>(m, vector<FP>(m));
	for (int r = 0; r < m; r++)
	for (int c = 0; c < m; c++)
	{
		fscanf(pIn, "%lf", &dd);
		M[r][c] = log10(dd);
	}

	T = vector<vector<FP>>(m, vector<FP>(m));
	for (int r = 0; r < m; r++)
	for (int c = 0; c < m; c++)
	{
		fscanf(pIn, "%lf", &dd);
		T[r][c] = log10(dd);
	}

	return 0;
}

