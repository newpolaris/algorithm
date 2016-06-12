#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<double> vd;

int main()
{
#ifdef _DEBUG
	freopen("genius.in", "r", stdin);
#endif
	int C, N, K, M;
	cin >> C;
	while (C--) {
		cin >> N >> K >> M;
		vector<int> L(N);
		for (auto& l : L) cin >> l;
		vector<vd> T(N, vd(N));
		for (auto& t : T)
			for (auto& tt : t)
				cin >> tt;
		vector<double> Pref(M);
		for (auto& p : Pref) cin >> p;

		vector<vd> cache(5, vd(N));
		cache[0][0] = 1.0;
		for (int t = 1; t <= K; t++) {
			for (int i = 0; i < N; i++) {
				double& prob = cache[t % 5][i];
				prob = 0.0;
				for (int p = 0; p < N; p++) {
					int prevT = (t - L[p] + 5)%5;
					prob += cache[prevT][p] * T[p][i];
				}
			}
		}
		vd ret(Pref.size());
		for (int i = 0; i < Pref.size(); i++)
			for (int t = K - L[Pref[i]] + 1; t <= K; t++) 
				ret[i] += cache[t % 5][Pref[i]];
		for (auto r : ret)
			cout << r << " ";
		cout << endl;
	}
}
