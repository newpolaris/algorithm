#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>

using namespace std;

int k[100][10000];

int main()
{
#ifdef _DEBUG
	freopen("hyperspace_travel.in", "r", stdin);
#endif
	int N, M;
	cin >> N >> M;
	for (int n = 0; n < N; n++) 
		for (int m = 0; m < M; m++) 
			cin >> k[m][n];
	for (int m = 0; m < M; m++)
		sort(k[m], k[m]+N);

	for (int m = 0; m < M; m++) {
		int mid = (k[m][N/2] + k[m][N/2-1])/2;
		vector<int> c = { k[m][N/2], k[m][N/2-1], mid };

		auto sum = [&](int b) {
			long long d = 0;
			for (int n = 0; n < N; n++)
				d += abs(k[m][n] - b);
			return d;
		};
		vector<pair<long long, int>> l;
		for (auto cc : c)
			l.push_back({sum(cc), cc});
		sort(l.begin(), l.end());
		cout << l[0].second << " ";
	}
	cout << endl;

	return 0;
}

