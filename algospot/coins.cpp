#include <iostream>
#include <cstring>

using namespace std;

int M, C, coin[101], MOD = 1000000007, cache[101][5001];

int coins(int k, int c)
{
	if (c == 0) return 1;
	if (k <= 0 || c < 0) return 0;

	int& ret = cache[k][c];
	if (ret != 0) return ret;

	return ret = (coins(k - 1, c) + coins(k, c - coin[k-1])) % MOD;
}

int main()
{
#ifdef _DEBUG
	freopen("coins.in", "r", stdin);
#endif

	int T;

	cin >> T;
	while (T--)
	{
		cin >> M >> C;
		memset(cache, 0, sizeof(cache));

		for (int i = 0; i < C; i++) 
			cin >> coin[i];
		sort(coin, coin+C);
		cout << coins(C, M) << endl;
	}

	return 0;
}
