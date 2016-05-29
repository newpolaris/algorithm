#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
typedef vector<int> vi;
int dist[40320];
const int maxN = 8;

int perm(const vi& in)
{
	int index = 0;
	int position = 1;
	int factor = 1;
	for (int i = in.size() - 2; i >= 0; i--)
	{
		int count = 0;
		for (int k = i + 1; k < in.size(); k++)
			if (in[i] > in[k])
				count++;
		index += count*factor;
		factor *= ++position;
	}
	return index;
}

int GetReverse(const vi& L)
{
	vector<int> S(maxN);
	for (int i = 0; i < S.size(); i++) S[i] = i;

	int N = L.size();
	vector<pair<int,int>> pi;
	for (int i = 0; i < N; i++)
		pi.push_back({L[i], i});
	sort(pi.begin(), pi.end());

	vector<int> ans = S;
	for (int i = 0; i < N; i++)
		ans[i] = pi[i].second;

	queue<vi> q;
	q.push(S);

	int& d = dist[perm(ans)];
	if (d != -1) return d;

	while (!q.empty())
	{
		auto here = q.front();
		q.pop();

		int idxHere = perm(here);
		for (int i = 2; i <= maxN; i++)
		{
			for (int j = 0; j + i <= maxN; j++)
			{
				reverse(here.begin() + j, here.begin() + i + j);
				int idxThere = perm(here);
				if (dist[idxThere] == -1)
				{
					dist[idxThere] = dist[idxHere] + 1;
					q.push(here);
				}
				reverse(here.begin() + j, here.begin() + i + j);
			}
		}
	}

	return d;
}

int main()
{
#ifdef _DEBUG
	freopen("sortgame.in", "r", stdin);
#endif

	int C, N;
	scanf("%d", &C);

	memset(dist, -1, sizeof(dist));
	dist[0] = 0;

	while (C--)
	{
		scanf("%d", &N);
		vi L(N);
		for (auto& l : L)
			scanf("%d", &l);

		printf("%d\n", GetReverse(L));
	}

	return 0;
}

