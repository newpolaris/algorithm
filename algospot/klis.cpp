#define _CRT_SECURE_NO_WARNINGS

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

int lis(int S)
{
	int& ret = cache[S+1];
	if (ret >= 0) return ret;

	ret = 0;

	for (int s = S+1; s < N; s++)
	{
		if (S == -1 || L[S] < L[s])
		{
			ret = max(ret, 1 + lis(s));
		}
	}
	return ret;
}

ll max_k = (ll)numeric_limits<int>::max() + 10;

ll count(int S)
{
	ll& ret = ccache[S + 1];
	if (ret >= 0) return ret;

	if (lis(S) == 0)
		return ret = 1;
	ret = 0;
	for (int s = S + 1; s < N; s++)
	{
		if (lis(S) == lis(s) + 1 && (S == -1 || L[S] < L[s]))
		{
			ret = min(max_k, ret + count(s));
		}
	}
	return ret;
}

void kth(vector<int>& A, int S, ll k)
{
	int i = 0;

	vector<pair<int, int>> T;
	for (int s = S + 1; s < N; s++)
	{
		if (lis(S) == lis(s) + 1 && (S == -1 || L[S] < L[s]))
		{
			T.emplace_back(L[s], s);
		}
	}
	sort(T.begin(), T.end());

	int t, a;
	for (t = 0; t < T.size(); t++)
	{
		a = T[t].second;
		ll c = ccache[a + 1];
		if (k + c < K)
		{
			k += c;
		}
		else
		{
			kth(A, a, k);
			A.push_back(L[a]);
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

		vector<int> A;
		kth(A, -1, 0);

		printf("%lu\n", A.size());
		for (int i = A.size() - 1; i >= 0; --i)
			printf("%d%c", A[i], " \n"[i == 0]);
	}

	return 0;
}
