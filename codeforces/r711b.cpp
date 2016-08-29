#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
ll m[501][501];

int main()
{
#ifdef _DEBUG
	freopen("r711b.in", "r", stdin);
#endif

	int n, tr, tc;
	cin >> n;
	if (n == 1) {
		cout << 5 << endl;
		return 0;
	}
	for (int r = 0; r < n; r++) {
	for (int c = 0; c < n; c++) {
		cin >> m[r][c];
		if (m[r][c] == 0) {
			tr = r;
			tc = c;
		}
	}
	}
	int rt = (tr == 0 ? 1 : 0);
	ll sum = 0;
	for (int i = 0; i < n; i++)
		sum += m[rt][i];
	ll hand = 0;
	for (int i = 0; i < n; i++)
		hand += m[tr][i];
	ll newnum = sum - hand;
	m[tr][tc] = newnum;

	vector<ll> list;
	for (int r = 0; r < n; r++) {
		ll sum = 0;
		for (int c = 0; c < n; c++) 
			sum += m[r][c];
		list.push_back(sum);
	}
	for (int c = 0; c < n; c++) {
		ll sum = 0;
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

	bool bScc = all_of(list.begin(), list.end(), [&](int i){ return list.front() == i; });
	if (newnum <= 0)
		bScc = false;
	cout << ( bScc ? newnum : -1 ) << endl;
	return 0;
}
