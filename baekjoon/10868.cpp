#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> tree;

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
		tree[i] = min(tree[2*i], tree[2*i+1]);
}

int Inf = (1<<9) + 1;

int query(int L, int R)
{
	int S = L + P;
	int E = R + P;

	int minV = Inf;
	while (S <= E)
	{
		if (S % 2 == 1)
		{
			minV = min(minV, tree[S]);
			S++;
		}
		if (E % 2 == 0)
		{
			minV = min(minV, tree[E]);
			E--;
		}
		S /= 2; 
		E /= 2;
	}
	return minV;
}

int main()
{
#ifdef _DEBUG
	freopen("10868.in", "r", stdin);
#endif

	int n, k;
	scanf("%d%d", &n, &k);

	vector<int> Array(n, Inf);
	for (auto& a : Array)
		scanf("%d", &a);

	P = 1;
	while (P < n)
		P *= 2;

	tree = vector<int>(P * 2);
	copy(Array.begin(), Array.end(), tree.begin() + P);

	init();

	while (k--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		cout << query(a-1, b-1) << endl;
	}
	return 0;
}
