#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
vector<ll> L;
int LeafStart;
int n, m, k;

ll init(int C)
{
	if (LeafStart <= C)
		return L[C];
	L[C] = init(C * 2 + 1) + init(C * 2 + 2);
	return L[C];
}


ll sum(int C, int RS, int RE, int S, int E)
{
	if (E > RE || S < RS) return 0LL;
	if (S > E) return 0LL;

	if (RS == S && RE == E)
		return L[C];

	int Mid = (RS + RE)/2;

	ll total = 0;
	total += sum(C * 2 + 1, RS, Mid, S, min(E, Mid));
	total += sum(C * 2 + 2, Mid + 1, RE, max(S, Mid + 1), E);
	return total;
}

ll Sum(int S, int E)
{
	return sum(0, 0, LeafStart, S - 1, E - 1);
}

void update(int C, int Level, int T, int V)
{
	int TotalLen = LeafStart + 1;
	int Len = TotalLen / Level;
	int Count = (C - Level + 1);
	int RS = Len * Count;
	int RE = RS + Len - 1;

	if (RS > T) return;
	if (RE < T) return;
	if (RS == RE && RS == T)
	{
		L[C] = V;
		return;
	}

	int LC = C * 2 + 1;
	int RC = C * 2 + 2;

	update(LC, Level*2, T, V);
	update(RC, Level*2, T, V);

	L[C] = L[LC] + L[RC];
}

void Update(int L, int V)
{
	update(0, 1, L - 1, V);
}

int main()
{
#ifdef _DEBUG
	fstream fin("2042.in");
	istream& in = fin;
#else
	istream& in = cin;
#endif

	in >> n >> m >> k;
	vector<ll> N(n);
	for (auto& e : N)
		in >> e;

	int h = ceil(log2(n));
	int size = pow(2.0, h+1);
	LeafStart = pow(2.0, h) - 1;
	L = vector<ll>(size);
	copy(N.begin(), N.end(), L.begin() + LeafStart);

	init(0);

	m += k;
	while (m--)
	{
		int a, b, c;
		in >> a >> b >> c;

		if (a == 1)
			Update(b, c);
		else if (a == 2)
			cout << Sum(b, c) << endl;
	}
	return 0;
}
