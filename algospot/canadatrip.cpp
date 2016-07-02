#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("canadatrip.in", "r", stdin);
#endif
	int T, N, K;

	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &N, &K);
		vector<int> L(N), M(N), G(N);
		for (int i = 0; i < N; i++)
			scanf("%d%d%d", &L[i], &M[i], &G[i]);
		int lo = 0, hi = 8030000;
		auto p = [&](int d) {
			int count = 0;
			for (int i = 0; i < N; i++)
			{
				int st = L[i] - M[i];
				if (d < st) continue;
				int c = (min(d, L[i]) - st) / G[i] + 1;
				count += c;
			}
			return count >= K;
		};

		while (lo < hi)
		{
			int mid = lo + (hi-lo)/2;
			if (p(mid))
				hi = mid;
			else
				lo = mid+1;
		}
		printf("%d\n", lo);
	}

	return 0;
}
