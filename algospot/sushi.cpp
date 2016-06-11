#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N, Max, Min;

int main()
{
#ifdef _DEBUG
	freopen("sushi.in", "r", stdin);
#endif
	
	int C;
	cin >> C;
	while (C--)
	{
		int M;
		cin >> N >> M;
		M /= 100;
		vector<int> Cost(N);
		vector<int> pref(N);
		for (int i = 0; i < N; i++)
			cin >> Cost[i] >> pref[i];
		for (auto& c : Cost) c /= 100;
		vector<int> cache(201);

		int ret = 0;
		cache[0] = 0;
		for (int budget = 1; budget <= M; ++budget) {
			int cand = 0;
			for (int i = 0; i < N; i++)
				if (budget >= Cost[i])
					cand = max(cand, cache[(budget - Cost[i])%201] + pref[i]);
			cache[budget % 201] = cand;
			ret = max(ret, cand);
		}

		cout << ret << endl;
	}

	return 0;
}
