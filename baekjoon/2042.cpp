#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

vector<ll> L;
int LeafStart;

ll init(int C)
{
	if (LeafStart <= C)
		return L[C];

	L[C] = init(C * 2 + 1) + init(C * 2 + 2);

	return L[C];
}

ll sum(int C, int RS, int RE, int S, int E)
{
	if (RS == S && RE == E)
		return L[C];

	int Mid = (RS + RE)/2;
	ll total = 0;
	if (Mid < S)
		total += sum(C * 2 + 1, RS, Mid, S, Mid);
	if (Mid < E)
		total += sum(C * 2 + 2, Mid+1, RE, Mid+1, E);
	return total;
}

ll TotalSum(int S, int E)
{
	return sum(0, 0, L.size() - LeafStart, S, E);
}

void update(int L, int V)
{
}

int main()
{
#ifdef _DEBUG
	fstream fin("2042.in");
	istream& in = fin;
#else
	istream& in = cin;
#endif

	int n, m, k;
	in >> n >> m >> k;
	vector<int> N(n);
	for (auto& e : N)
		in >> e;

	int h = log2(n);
	int size = pow(2.0, h+1) - 1;
	LeafStart = pow(2.0, h) + 1;

	L = vector<ll>(size);
	copy(N.begin(), N.end(), L.begin() + LeafStart);

	m += k;
	while (m--)
	{
		int a, b, c;
		in >> a >> b >> c;

		if (a == 0)
			cout << TotalSum(a, b) << endl;
		else if (a == 1)
			update(b, c);
	}
}

