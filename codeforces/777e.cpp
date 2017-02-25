#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

#define x first
#define y second

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("777e2.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, h, n;
	cin >> n;
	vector<pair<int,pair<int,int>>> ring(n);
	for (auto& r : ring) 
		cin >> r.y.x >> r.x >> r.y.y;
	sort(ring.begin(), ring.end());
	long long maxH = 0, height = ring[n-1].y.y;
	for (int i = n-2; i >= 0; i--) {
		if (ring[i+1].y.x > ring[i].x) {
			maxH = max(height, maxH);
			height = 0;
		}
		height += ring[i].y.y;
	}
	maxH = max(height, maxH);
	cout << maxH << endl;
	return 0;
}
