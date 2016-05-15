#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <iomanip>

using namespace std;

int C, N, M, K;
const int B = 1E9+1;
int bino[201][201];

void calcBino()
{
	memset(bino, 0, sizeof(bino));
	for (int i = 0; i < 201; i++)
	{
		bino[i][0] = bino[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			bino[i][j] = min(B, bino[i-1][j-1] + bino[i-1][j]);
		}
	}
}

void Generate(int n, int m, string s)
{
	if (K < 0) return;
	if (n == 0 && m == 0)
	{
		if (K == 0)
			cout << s << endl;
		--K;
		return;
	}

	if (bino[n+m][n] <= K) 
	{
		K -= bino[n+m][n];
		return;
	}

	if (n > 0) Generate(n-1, m, s + "-");
	if (m > 0) Generate(n, m - 1, s + "o");
}

int main()
{
#if _DEBUG
	ifstream fin("morse.in");
	istream& in = fin;
#else
	istream& in = cin;
#endif

	in >> C;

	calcBino();

	while (C--)
	{
		in >> N >> M >> K;
		--K;
		Generate(N, M, "");
	}
	
	return 0;
}
