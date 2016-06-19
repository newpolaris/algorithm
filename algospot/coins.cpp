#include <iostream>

using namespace std;

int M, C, coin, MOD = 1000000007;
long long cache[5001];

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

		int coin;
		for (int i = 0; i < C; i++) 
		{
			cin >> coin;
			cache[coin]++;
			for (int k = 1; k + coin <= M; k++)
				cache[k+coin] += cache[k];
		}
		cout << (cache[M] % MOD) << endl;
	}

	return 0;
}
