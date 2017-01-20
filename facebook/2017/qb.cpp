#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int count(vector<int> list) {
	if (list.size() <= 0) 
		return 0;
	int k = ceil(50.0 / list[0]);
	if (list.size() < k)
		return 0;
	return 1 + count(vector<int>(list.begin()+1, list.end()-(k-1)));
}

int main() {
	freopen("qb.in", "r", stdin);
#ifndef _DEBUG
	freopen("qb.out", "w", stdout);
#endif
	int T, N;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		vector<int> items(N);
		for (auto& i : items)
			cin >> i;
		sort(&items[0], &items[N], greater<int>());
		cout << "case #" << t << ": " << count(items) << endl;
	}

	return 0;
}
