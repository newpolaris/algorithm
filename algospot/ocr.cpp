#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

typedef float FP;

int m, q, n;
vector<vector<FP>> M, T;
vector<FP> B;
vector<int> S;

const int MMax = 501;
const int QMax = 101;
FP cache[QMax][MMax];
int choose[QMax][MMax];

int INF = 987654321;

FP GetTP(int step, int i, int prev)
{
	FP Tt = (step == 0) ? B[i] : T[prev][i];
	FP Mt = M[i][S[step]];

	return Tt + Mt;
}

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
		FP Tp = GetTP(step, i, prev);
		if (Tp < -INF) continue;
		
		Tp += search(step+1, i);
		if (Tp > ret)
		{
			ret = Tp;
			choose[step][prev] = i;
		}
	}

	return ret;
}

void reconstruct(vector<int>& L, int prev, int step)
{
	if (L.size() == S.size())
		return;
	int Next = choose[step][prev];
	L.push_back(Next);
	reconstruct(L, Next, step+1);
}

int main()
{
#if _DEBUG
	freopen("ocr.in", "r", stdin);
#endif

	char ss[11];
	FP dd;

	scanf("%d%d", &m, &q); 

	vector<string> R(m);
	for (auto& r : R)
	{
		scanf("%s", ss);
		r = string(ss);
	}

	B = vector<FP>(m);
	for (int c = 0; c < m; c++)
	{
		scanf("%f", &dd);
		B[c] = log10(dd);
	}

	T = vector<vector<FP>>(m, vector<FP>(m));
	for (int r = 0; r < m; r++)
	for (int c = 0; c < m; c++)
	{
		scanf("%f", &dd);
		T[r][c] = log10(dd);
	}

	M = vector<vector<FP>>(m, vector<FP>(m));
	for (int r = 0; r < m; r++)
	for (int c = 0; c < m; c++)
	{
		scanf("%f", &dd);
		M[r][c] = log10(dd);
	}

	while (q--)
	{
		for (int r = 0; r < MMax; r++)
		for (int c = 0; c < QMax; c++)
			cache[c][r] = 1.0;

		memset(&choose, -1, sizeof(choose));

		scanf("%d", &n);
		S = vector<int>(n);
		for (auto& i : S)
		{
			scanf("%s", ss);
			string s(ss);
			auto it = find(R.begin(), R.end(), s);
			i = distance(R.begin(), it);
		}

		search(0, 0);
		vector<int> L;
		reconstruct(L, 0, 0);

		for (int i = 0; i < L.size(); i++)
			printf("%s ", R[L[i]].c_str());
		printf("\n");
	}

	return 0;
}

