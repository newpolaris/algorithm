#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <iomanip>

using namespace std;

typedef double FP;

FP cache[51][101];
vector<vector<FP>> M;
vector<FP> Order;
int C, N, D, P;

double search(int here, int days, FP percent)
{
	double& ret = cache[here][days];
	if (ret > -0.5)
		return ret;

	if (days == 0)
	{
		if (here == P)
			return percent;
		return 0.0;
	}

	ret = 0.0;
	for (int n = 0; n < N; n++)
	{
		if (!M[here][n])
			continue;
		ret += search(n, days-1, percent/Order[n]);
	}

	return ret;
}

int main()
{
#if _DEBUG
	ifstream fin("numb3rs.in");
	istream& in = fin;
#else
	istream& in = cin;
#endif

	in >> C;

	while (C--)
	{
		in >> N >> D >> P;

		M = vector<vector<FP>>(N, vector<FP>(N));
		Order = vector<FP>(N);

		for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			in >> M[y][x];

		for (int y = 0; y < N; y++)
		{
			FP order = 0.0;
			for (int x = 0; x < N; x++)
				order += M[y][x];
			Order[y] = order;
		}

		for (int n = 0; n < N; n++)
		for (int d = 0; d <= D; d++)
			cache[n][d] = -1.0;

		for (int n = 0; n < N; n++)
			search(n, D, 1.0);

		int T;
		in >> T;
		vector<int> TL(T);
		for (auto& t : TL)
			in >> t;

		cout << fixed << setprecision(8);
		for (int i = 0; i < TL.size(); i++)
			cout << cache[TL[i]][D] << " \n"[i == T - 1];
	}
	
	return 0;
}
