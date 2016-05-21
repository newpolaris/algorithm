#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
	ll n, a, b, c, d;

	cin >> n >> a >> b >> c >> d;

	vector<ll> cons = { a - d,  a + b - c - d, b - c };
	ll maxn = *max_element(cons.begin(), cons.end());
	ll minn = *min_element(cons.begin(), cons.end());

	ll able = n - max(0LL, maxn) + min(0LL, minn);
	if (able < 0)
		able = 0;

	cout << (able * n) << endl;

	return 0;
}
