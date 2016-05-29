#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <string.h>
#include <assert.h>

using namespace std;
typedef vector<int> vi;

int dist[1<<24];

// bit 버전
int perm(const vi& in)
{
	int ret = 0;
	for (int i = in.size() - 1; i >= 0; --i)
	{
		assert(in[i] < 8);
		int shift = (in.size() - 1 - i) * 3;
		ret += (in[i] << shift);
	}
	return ret;
}

int GetReverse(const vi& L)
{
	int N = L.size();

	auto ans = L;
	sort(ans.begin(), ans.end());

	queue<vi> q;
	q.push(L);

	memset(dist, -1, sizeof(dist));
	dist[perm(L)] = 0;

	while (!q.empty())
	{
		auto here = q.front();
		q.pop();

		if (here == ans)
			return dist[perm(ans)];

		int distHere = perm(here);
		for (int i = 2; i <= N; i++)
		{
			for (int j = 0; j <= N - i; j++)
			{
				reverse(here.begin() + j, here.begin() + i + j);
				int distThere = perm(here);
				if (dist[distThere] == -1)
				{
					dist[distThere] = dist[distHere] + 1;
					q.push(here);
				}
				reverse(here.begin() + j, here.begin() + i + j);
			}
		}
	}

	return -1;
}

vi remap(const vi& L)
{
	vector<pair<int,int>> VP;
	for (int i = 0; i < L.size(); i++)
		VP.push_back({L[i], i});
	sort(VP.begin(), VP.end());

	vi R(L.size());
	for (int i = 0; i < L.size(); i++)
		R[VP[i].second] = i;

	return R;
}

int main()
{
#ifdef _DEBUG
	//freopen("/Users/newpolaris/Projects/algorithm/algospot/sortgame.in", "r", stdin);
	freopen("sortgame.in", "r", stdin);
#endif

	int C, N;
	scanf("%d", &C);
	while (C--)
	{
		scanf("%d", &N);
		vi L(N);
		for (auto& l : L)
			scanf("%d", &l);

		L = remap(L);

		for (int i = 0; i < 30; i++)
			printf("%d\n", GetReverse(L));
	}

	return 0;
}

