#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

#define ALL(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define SZ(x) (int((x).size()))

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("1852.in", "r", stdin);
#endif
	int c, length, n;
	cin >> c; 
	while (c--) {
		cin >> length >> n;
		vector<int> ants(n);
		REP(i, 0, n) cin >> ants[i];
		int minL = -1, maxL = -1;
		REP(i, 0, n) {
			int dist = min(ants[i], length-ants[i]);
			minL = max(minL, dist);
		}
		REP(i, 0, n) {
			int dist = max(ants[i], length-ants[i]);
			maxL = max(maxL, dist);
		}
		cout << minL << " " << maxL << endl;
	}
	return 0;
}
