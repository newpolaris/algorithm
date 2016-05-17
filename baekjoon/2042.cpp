#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

vector<int> Array;
vector<ll> tree;

int P;

//  Tree:
//
//  root - 1
//        / \
//     Even Odd
//
void init()
{
	for (int i = P - 1; i >= 1; --i)
		tree[i] = tree[2*i] + tree[2*i+1];
}

void update(int C, int V)
{
	int N = C + P;
	tree[N] = V;
	for (int i = N / 2; i >= 1; i /= 2)
		tree[i] = tree[2*i] + tree[2*i+1];
}

ll sum(int L, int R)
{
	int S = L + P;
	int E = R + P;

	ll Adds = 0LL;
	while (S <= E)
	{
		if (S % 2 == 1)
		{
			Adds += tree[S];
			S++;
		}
		if (E % 2 == 0)
		{
			Adds += tree[E];
			E--;
		}
		S /= 2; 
		E /= 2;
	}
	return Adds;
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

	Array = vector<int>(n);
	for (auto& a : Array)
		in >> a;

	P = 1;
	while (P < n)
		P *= 2;

	tree = vector<ll>(P * 2);
	copy(Array.begin(), Array.end(), tree.begin() + P);

	init();

	m += k;
	while (m--)
	{
		int a, b, c;
		in >> a >> b >> c;

		if (a == 1)
			update(b-1, c);
		else if (a == 2)
			cout << sum(b-1, c-1) << endl;
	}
	return 0;
}
