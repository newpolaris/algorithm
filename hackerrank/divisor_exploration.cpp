#include <iostream>

typedef long long ll;

using namespace std; 

int main()
{
#ifdef _DEBUG
	freopen("divisor_exploration.in", "r", stdin);
#endif
	int d, m, a;
	scanf("%d", &d);
	while (d--) {
		scanf("%d%d", &m, &a);
		ll mod = 1e9+7;
		ll c = 1;
		for (int i = 0; i < m; i++) {
			c = c * (((1+i+1+a)*(1+i+2+a)/2) % mod);
			c = c % mod;
		}
		int ans = c % mod;
		printf("%d\n", ans);
	}
}
