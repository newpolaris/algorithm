#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int minGet(vector<int> a, vector<int> b) {
	int i, j = 0, n = a.size();
	for (i = 0; i < n; i++) {
		bool bFound = false;
		for (; j < n; j++) {
			if (a[i] <= b[j]) {
				bFound = true;
				break;
			}
		}
		if (bFound == true) {
			j++;
		} else {
			break;
		}
	}
	return n - i;
}

int maxHit(vector<int> a, vector<int> b) {
	int i, j = 0, n = a.size();
	int cnt = 0;
	for (i = 0; i < n; i++) {
		bool bFound = false;
		for (; j < n; j++) {
			if (a[i] < b[j]) {
				cnt++;
				bFound = true;
				break;
			}
		}
		if (bFound == true) {
			j++;
		} else {
			break;
		}
	}
	return cnt;
}

int main() {
#ifdef _DEBUG
	freopen("777b0.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	string sa, sb;
	vector<int> a, b;
	cin >> n;
	cin >> sa >> sb;
	for (auto s : sa) a.push_back(s - '0');
	for (auto s : sb) b.push_back(s - '0');

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	cout << minGet(a, b) << endl;
	cout << maxHit(a, b) << endl;
	return 0;
}
