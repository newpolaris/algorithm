#include <iostream>

typedef long long ll;

using namespace std; 

const int N = 200015;
const int mod = 1e9+7;
int cache[N];

ll moddiv(ll x, ll y, ll m) {
	long long ans = 1;
	while (y > 0) {
		if (y % 2 != 0) {
			ans *= x;
			ans %= m;
		}
		x *= x;
		x %= m;
		y /= 2;
	}
	return ans;
}

int main()
{
#ifdef _DEBUG
	freopen("divisor_exploration.in", "r", stdin);
#endif
	int d, m, a;

	scanf("%d", &d);
	cache[0] = 0;
	for (int i = 1; i < N; i++) {
		ll p = cache[i-1];
		cache[i] = (p + i) % mod;
	}
	for (int i = 2; i < N; i++) {
		ll p = cache[i-1];
		ll q = cache[i];
		cache[i] = (p*q) % mod;
	}
	
	while (d--) {
		scanf("%d%d", &m, &a);
		ll div2 = moddiv(cache[a+1], mod-2, mod);
		ll A = cache[a+m+1];
		int ans = (A * div2) % mod;
		printf("%d\n", ans);
	}
}
