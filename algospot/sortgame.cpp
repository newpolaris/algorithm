#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
typedef vector<int> vi;

int perm(const vi& in)
{
	int index = 0;
	int position = 1;
	int factor = 1;
	for (int i = in.size() - 2; i >= 0; i--)
	{
		int count = 0;
		for (int k = i + 1; k < in.size(); k++)
			if (in[i] < in[k])
				count++;
		index += count*factor;
		factor *= ++position;
	}
	return index;
}

int GetReverse(const vi& L)
{
	int N = L.size();

	auto ans = L;
	sort(ans.begin(), ans.end());

	queue<vi> q;
	q.push(L);


	int Length = 1;
	for (int i = 2; i <= N; i++)
		Length *= i;

	vi dist(Length, -1);
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

		printf("%d\n", GetReverse(L));
	}

	return 0;
}

