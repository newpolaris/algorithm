#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

const int MOD = 10000000;

int cache[101][101];

int dp(int n, int a, int Factor)
{
	if (n <= 0)
		return Factor;

	int& tFactor = cache[n][a];
	if (tFactor != 0)
		return Factor * tFactor % MOD;

	for (int i = 1; i <= n; i++)
	{
		tFactor += dp(n-i, i, (a + i - 1));
		tFactor %= MOD;
	}

	return Factor * tFactor % MOD;
}

int main()
{
	int C;
	cin >> C;

	while (C--)
	{
		int n;
		cin >> n;

		memset(&cache, 0, sizeof(cache));
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			sum += (dp(n-i, i, 1) % MOD);
			sum %= MOD;
		}
		cout << sum << endl;
	}

	return 0;
}

