#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
int main() {
#ifdef _DEBUG
	freopen("20171CA.in", "r", stdin);
#else
	freopen("2017QB.in0", "r", stdin);
	freopen("2017QB.out0", "w", stdout);
#endif
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int K, N;
		cin >> N >> K;
		vector<pair<int, int>> cake(N);
		vector<int> radius;
		for (auto& c : cake) {
			radius.push_back(c.first);
			cin >> c.first >> c.second;
		}
		double sum = 0.0;
		vector<bool> used(N, false);
		{
			priority_queue<pair<int, double>> sides;
			// side + area
			for (int i = 0; i < N; i++) {
				auto r = cake[i].first;
				auto h = cake[i].second;
				double side = 2 * M_PI * r * h;
				sides.push({side, i});
			}
			for (int i = 0; i < K-1; i++) {
				auto top = sides.top();
				sum += top.first;
				used[top.second] = true;
			}
		}
		{
			priority_queue<pair<int, double>> areas;
			// side + area
			for (int i = 0; i < N; i++) {
				auto r = cake[i].first;
				auto h = cake[i].second;
				double area = M_PI * r*r *  + 2 * M_PI * r * h;
				areas.push({area, i});
			}
		}
		while (true) {
			auto top = areas.top();
			top[i]
		}
		



		cout << "Case #" << t << ": ";
		cout << string(num.begin()+st, num.end()) << endl;
	}
	return 0;
}
