#include <iostream>
#include <cstring>

using namespace std;

const int MaxN = 500, MaxK = 100, MOD = 1000000007;
// number of ways to generate [K][R]
int cache[MaxK+1][MaxN];

int main()
{
#ifdef _DEBUG
	freopen("escapegeese.in","r",stdin);
#endif
	int T, N, K;

	cin >> T;
	while (T--)
	{
		cin >> N >> K;
		memset(cache, 0, sizeof(cache));
		// case 0, each include, not include
		cache[0][0] = cache[1][0] = 1;
		for (int n = 1; n < N; n++) {
			// to disable bubbling calc revsersly
			for (int k = K; k >= 1; k--) {
				for (int r = 0; r < N; r++) {
					int& a = cache[k][r];
					// find such one fit that cond. (need to [k][r] after inlcude n)
					int b = cache[k-1][(r - n + N) % N];
					a = (a + b) % MOD;
				}
			}
		}
		cout << cache[K][0] << endl;
	}
	return 0;
}
