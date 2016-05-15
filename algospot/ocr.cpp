#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

typedef double FP;

int m, q, n;
vector<vector<FP>> M, T;
vector<FP> B;
vector<int> S;

const int MMax = 501;
const int QMax = 101;
FP cache[QMax][MMax];
FP value[QMax][MMax][MMax];

int INF = 987654321;

FP search(int step, int prev)
{
	if (step == n)
		return 0.0;

	FP& ret = cache[step][prev];
	if (ret < 1.0)
		return ret;	

	ret = -INF;
	for (int i = 0; i < m; i++)
	{
		FP Tt = (step == 0) ? B[i] : T[prev][i];
		FP Mt = M[i][S[step]];
		FP Tp = Tt + Mt;

		// if (isinf(Tp)) 
		//		continue;
		
		auto tt = Tp + search(step+1, i);
		value[step][prev][i] = tt;
		ret = max(ret, tt);
	}

	return ret;
}

void reconstruct(vector<int>& L, int prev, int step)
{
	if (step == S.size())
		return;

	int i = 0;
	FP minV = -INF;

	for (int c = 0; c < m; c++)
	{
		auto t = value[step][prev][c];
		if (t > 0.5) continue;
		if (minV < t)
		{
			i = c;
			minV = t;
		}
	}
	L.push_back(i);
	reconstruct(L, i, step+1);
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

	vector<string> R(m);
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

	T = vector<vector<FP>>(m, vector<FP>(m));
	for (int r = 0; r < m; r++)
	for (int c = 0; c < m; c++)
	{
		fscanf(pIn, "%lf", &dd);
		T[r][c] = log10(dd);
	}

	M = vector<vector<FP>>(m, vector<FP>(m));
	for (int r = 0; r < m; r++)
	for (int c = 0; c < m; c++)
	{
		fscanf(pIn, "%lf", &dd);
		M[r][c] = log10(dd);
	}

	while (q--)
	{
		for (int r = 0; r < MMax; r++)
		for (int c = 0; c < QMax; c++)
		{
			cache[c][r] = 1.0;
		}

		for (int r2 = 0; r2 < MMax; r2++)
		for (int r = 0; r < MMax; r++)
		for (int c = 0; c < QMax; c++)
			value[c][r2][r] = 1.0;

		fscanf(pIn, "%d", &n);
		S = vector<int>(n);
		for (auto& i : S)
		{
			fscanf(pIn, "%s", ss);
			string s(ss);
			auto it = find(R.begin(), R.end(), s);
			i = distance(R.begin(), it);
		}
		FP P = search(0, 0);
		vector<int> L;
		reconstruct(L, 0, 0);

		for (int i = 0; i < L.size(); i++)
			printf("%s ", R[L[i]].c_str());
		printf("\n");
	}

	return 0;
}

