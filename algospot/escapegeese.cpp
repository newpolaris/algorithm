#include <iostream>
#include <cstring>

using namespace std;

const int MaxN = 500, MaxK = 100, MOD = 1000000007;
int cache[2][MaxK+1][MaxN];

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
		cache[0][0][0] = cache[0][1][0] = 1;
		for (int n = 1; n < N; n++) {
			int PP = (n - 1) % 2, NN = n % 2;
			for (int k = 0; k <= K; k++) {
				for (int r = 0; r < N; r++) {
					int a = cache[PP][k][r];
					int b = (k > 0) ? cache[PP][k-1][(r - n + N) % N] : 0;
					cache[NN][k][r] = (a + b) % MOD;
				}
			}
		}
		cout << cache[(N-1)%2][K][0] << endl;
	}
	return 0;
}
