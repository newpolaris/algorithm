#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

typedef long long ll;

ll n, m, k;
ll c[101];
ll p[101][101];
ll cache[101][101][101];
const ll inf = 987654321987654321;

ll cost(ll idx, ll pci, ll ck) {
	if (ck > k) 
		return inf;
	if (idx == n) {
		if (ck == k)
			return 0;
		else 
			return inf;
	}

	ll& ret = cache[idx][pci][ck];
	if (ret >= 0) 
		return ret;

	ret = inf;
	ll ci = c[idx];
	if (ci == 0) {
		for (ll i = 1; i <= m; i++) {
			ll add = i != pci;
			ret = min(ret, cost(idx+1, i, ck+add) + p[idx][i-1]);
		}
	} else {
		ll add = (pci < 0 || ci != pci);
		ret = min(ret, cost(idx+1, ci, ck+add));
	}
	return ret;
}

int main()
{
#ifdef _DEBUG
	freopen("711c.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(0); 
	cin >> n >> m >> k;
	for (ll i = 0; i < n; i++)
		cin >> c[i];

	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> p[i][j];
		}
	}
	memset(cache, -1, sizeof(cache));
	ll ans = cost(0, 0, 0);
	cout << (ans == inf ? -1 : ans) << endl;
	
	return 0;
}
