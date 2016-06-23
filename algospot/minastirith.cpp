#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<pair<double, double>, int> PDI;

int main()
{
#ifdef _DEBUG
	freopen("minastirith.in", "r", stdin);
#endif
	
	int C, N;
	cin >> C;
	while (C--) {
		cin >> N;
		double x, y, r;
		vector<PDI> L;
		for (int i = 0; i < N; i++)
		{
			cin >> x >> y >> r;

			double S, E;
			if (r >= 16.0)
				S = 0.0, E = 2.0;
			else
			{
				double A = atan2(y, x) / M_PI;
				double th = acos(1.0 - r*r / (2*8*8)) / M_PI;
				S = A - th;
				if (S < 0.0) S += 2;
				if (S > 2.0) S -= 2;
				E = S + 2.0*th;
			}
			L.push_back(make_pair(make_pair(S, -E), i));
			if (E > 2.0) 
				L.push_back(make_pair(make_pair(0.0, 2.0 - E), i));
		}
		// eliminate including
		sort(L.begin(), L.end());
		vector<PDI> K;
		K.push_back(L[0]);
		double s = L[0].first.first, e = -L[0].first.second;
		double EPS = 0.0000001;
		for (int i = 1; i < L.size(); i++)
		{
			double ns = L[i].first.first;
			double ne = -L[i].first.second;
			if (ne - e > EPS)
			{
				K.push_back(L[i]);
				s = ns; e = ne;
			}
		}
		sort(K.begin(), K.end());
		// range check
		set<int> sol;
		s = 0.0;
		e = 0.0;
		bool bComplete = false;
		int idx = -1;
		while (true) {
			vector<int> T;
			for (int i = idx + 1; i < K.size(); i++) {
				double ns = K[i].first.first;
				double ne = -K[i].first.second;
				int nk = K[i].second;
				if (ns - e > EPS) break;
				T.push_back(i);
			}
			if (T.size() <= 0) 
				break;
			idx = T.back();
			double ne = -K[idx].first.second;
			int nk = K[idx].second;
			sol.insert(nk);
			e = ne;
			if (e - 2.0 > EPS || 2.0 - e < EPS) {
				bComplete = true;
				break;
			}
		}
		if (!bComplete)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << sol.size() << endl;
	}
	return 0;
}
