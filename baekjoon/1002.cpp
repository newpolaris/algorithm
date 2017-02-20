#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <cmath>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define fori(i, a, b) for (int i = (a), i##_end_ = (b); i > i##_end_; --i)

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		vector<int> area[2];
		area[0].resize(3);
		area[1].resize(3);
		forn(i, 0, 2) forn(j, 0, 3) cin >> area[i][j];
		/* tag: FAIL
		 * 틀린건 아니고 including 시 처리하는 방법이 생각나지 않아서
		 * 
		 *	double innerRange = sqrt(double(dist))+min(a[2],b[2]);
		 *  double z2 = max(a[2],b[2]);
		 *  if (innerRange < z2) return 0;
		 *  if (innerRange == z2) return 1;
		 *
		 * 위와 같이 처리했는데,
		 * (r1-r2)^2, (r1+r2)^2, dist^2 와 비교하면 된다.
		 */
		auto numPos = [](vector<int> a, vector<int> b) {
			if (a == b) return -1;
			auto dx = a[0]-b[0], dy = a[1]-b[1];
			auto dist = dx*dx + dy*dy;
			auto ro = a[2]+b[2];
			auto ri = a[2]-b[2];
			ro = ro * ro, ri = ri * ri;
			if (dist > ro) return 0;
			if (dist < ri) return 0;
			if (dist == ro) return 1;
			if (dist == ri) return 1;
			return 2;
			
		};
		cout << numPos(area[0], area[1]) << endl;
	}

	return 0;
}
