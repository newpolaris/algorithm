#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;
ll K;
int L[500];
int cache[501];
ll ccache[501];

const ll max_k = (ll)numeric_limits<int>::max() + 10;

int lis(int S)
{
	int& ret = cache[S+1];
	if (ret != -1) return ret;

	ret = 1;
	for (int s = S+1; s < N; s++)
		if (S == -1 || L[S] < L[s])
			ret = max(ret, 1 + lis(s));
	return ret;
}

ll count(int S)
{
	ll& ret = ccache[S + 1];
	if (ret >= 0) return ret;

	if (lis(S) == 1)
		return ret = 1;

	ret = 0;
	for (int s = S + 1; s < N; s++)
		if (lis(S) == lis(s) + 1 && (S == -1 || L[S] < L[s]))
			ret = min(max_k, ret + count(s));
	return ret;
}

void kth(int S, ll k)
{
	if (S != -1) printf("%d ", L[S]);

	vector<pair<int, int>> T;
	for (int s = S + 1; s < N; s++)
		if (lis(S) == lis(s) + 1 && (S == -1 || L[S] < L[s]))
			T.emplace_back(L[s], s);
	sort(T.begin(), T.end());

	for (int t = 0; t < T.size(); t++)
	{
		int a = T[t].second;
		ll c = count(a);
		if (k + c < K)
			k += c;
		else
		{
			kth(a, k);
			break;
		}
	}
}

int main()
{
#ifdef _DEBUG
	freopen("klis.in", "r", stdin);
#endif

	int C;
	scanf("%d", &C);

	while (C--)
	{
		scanf("%d%lld", &N, &K);

		memset(cache, -1, sizeof(cache));
		memset(ccache, -1, sizeof(ccache));

		for (int i = 0; i < N; i++)
			scanf("%d", &L[i]);

		lis(-1);
		count(-1);

		printf("%d\n", lis(-1) - 1);
		kth(-1, 0);
		printf("\n");
	}

	return 0;
}
