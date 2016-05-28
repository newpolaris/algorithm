#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
typedef vector<int> vi;

int main()
{
#ifdef _DEBUG
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

		auto ans = L;
		sort(ans.begin(), ans.end());

		queue<vi> q;
		q.push(L);

		map<vi, int> dist;
		dist[L] = 0;

		while (!q.empty())
		{
			auto here = q.front();
			q.pop();

			if (here == ans)
				break;

			for (int i = 2; i <= N; i++)
			{
				for (int j = 0; j <= N - i; j++)
				{
					auto t = here;
					reverse(t.begin() + j, t.begin() + i + j);
					if (dist.end() == dist.find(t))
					{
						dist[t] = dist[here] + 1;
						q.push(t);
					}
				}
			}
		}

		int sol = dist[ans];
		printf("%d\n", sol);
	}

	return 0;
}

