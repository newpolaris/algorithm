#include <iostream>
#include <queue>
#include <functional>
#include <string.h>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef long long ll; 

int main() {
#ifdef _DEBUG
	freopen("1015c1.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, m, sum = 0, sumcomp = 0;
	cin >> n >> m;
	std::vector<ll> delta(n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		sum += a, sumcomp += b;
		delta[i] = a - b;
	}
	std::sort(delta.begin(), delta.end(), std::greater<ll>());
	if (sumcomp > m)
		cout << -1 << endl;
	else
	{
		int cnt = 0;
		for (int i = 0; i < delta.size(); i++)
		{
			if (sum <= m)
				break;
			sum -= delta[i];
			cnt++;
		}
		cout << cnt << endl;
	}

	return 0;
}
