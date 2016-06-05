#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("lunchbox.in", "r", stdin);
#endif
	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		vector<pair<int, int>> L(N);
		for (auto& l : L) cin >> l.second;
		for (auto& l : L) cin >> l.first;
		sort(L.begin(), L.end(), greater<pair<int,int>>());
		int sum = 0, t = 0;
		for (auto& l : L)
		{
			t += l.second;
			sum = max(sum, l.first + t);
		}
		cout << sum << endl;
	}
	return 0;
}
