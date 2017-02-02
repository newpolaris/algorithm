#include <iostream>
#include <cstring>

using namespace std;

int M, C, coin[101], MOD = 1000000007, cache[101][5001];

// count(n,i) = all i sum(count(n-coins(i),i))
int coins(int nextI, int remain) {
	if (remain < 0) return 0;
	if (remain == 0) return 1;
	auto& ret = cache[nextI][remain];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = nextI; i < C; i++) {
		ret += coins(i, remain - coin[i]);
		ret %= MOD;
	}
	return ret;
};

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
		memset(cache, -1, sizeof(cache));

		for (int i = 0; i < C; i++) 
			cin >> coin[i];
		sort(coin, coin+C);
		cout << coins(0, M) << endl;
	}

	return 0;
}
