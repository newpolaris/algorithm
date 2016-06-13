#include <iostream>
#include <iostream>
#include <string.h>

using namespace std;

int N;
int MOD = 1000000007;
int cache[501][101][500];

int count(int n, int k, int r)
{
	if (n > N) return 0;

	int& ret = cache[n][k][r];
	if (ret != -1) return ret;

	if (k == 0) return ret = (r == 0);

	return ret = count(n+1, k-1, (r+n)%N) % MOD + count(n+1, k, r) % MOD;
}

int main()
{
#ifdef _DEBUG
	freopen("escapegeese.in", "r", stdin);
#endif

	int T, K;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		memset(cache, -1, sizeof(cache));
		cout << count(0, K, 0) << endl;
	}
}
