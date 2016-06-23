#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<double, double> PD;

const double pi = 2.0 * acos(0);
const double EPS = 0.0000001;

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
		vector<PD> L;
		int minCount = 101;
		for (int i = 0; i < N; i++)
		{
			cin >> x >> y >> r;
			double S, E;
			if (r >= 16.0)
				minCount = 1;
			else
			{
				double A = atan2(y, x);
				double th = acos(1.0 - r*r / (2*8*8));
				S = fmod(2*pi + A - th, 2*pi);
				E = S + 2.0*th;
			}
			L.push_back(make_pair(S, E));
		}
		sort(L.begin(), L.end());
		for (int i = 0; i < L.size(); i++) {
			auto& k = L[i];
			if (k.second < 2*pi && k.first > 0.0)
				continue;
			int idx = -1;
			int count = 1;
			double s = fmod(k.second, 2*pi);
			double e = fmod(k.first, 2*pi);
			while (idx < (int)L.size()) {
				if (s - e > EPS || abs(e - s) < EPS) {
					minCount = min(minCount, count);
					break;
				}
				double ne = -1.0;
				int j = idx + 1;
				while (j < L.size()) {
					if (L[j].first - s > EPS) break;
					ne = max(ne, L[j].second);
					j++;
				}
				if (ne < 0) break;
				s = ne;
				count++;
				idx = j - 1;
			}
		}
		if (minCount == 101)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << minCount << endl;
	}
	return 0;
}
