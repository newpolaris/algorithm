#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
int n, tr, tc;
ll m[501][501];

bool check(ll goal) {
	ll sum = 0;
	for (int r = 0; r < n; r++) {
		sum = 0;
		for (int c = 0; c < n; c++) sum += m[r][c];
		if (sum != goal) return 0;
		sum = 0;
		for (int c = 0; c < n; c++) sum += m[c][r];
		if (sum != goal) return 0;
	}
	for (int c = 0; c < n; c++) {
		for (int r = 0; r < n; r++) 
			sum += m[r][c];
		list.push_back(sum);
	}
	ll xx = 0;
	for (int i = 0; i < n; i++)
		xx += m[i][i];
	list.push_back(xx);
	ll xy = 0;
	for (int i = 0; i < n; i++)
		xy += m[i][n-i-1];
	list.push_back(xy);

	return all_of(list.begin(), list.end(), [&](ll i){ return list.front() == i; });
}

int main()
{
#ifdef _DEBUG
	freopen("711b.in", "r", stdin);
#endif

	cin >> n;
	if (n == 1) { cout << 1 << endl; return 0; }
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			cin >> m[r][c];
			if (!m[r][c]) tr = r, tc = c;
		}
	}

	ll sumu = 0, sumv = 0;
	for (int i = 0; i < n; i++) {
		sumu += m[tr][i];
		sumv += m[(tr+1)%n][i];
	}
	if (sumv - sumu <= 0) { cout << -1 << endl; return 0; }
	m[tr][tc] = sumv - sumu;

	cout << ( bScc ? newnum : -1 ) << endl;
	return 0;
}
