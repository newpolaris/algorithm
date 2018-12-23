#include <iostream>
#include <queue>
#include <functional>
#include <string>
#include <string.h>
#include <algorithm>

#define x first
#define y second

using namespace std;

using ll = long long;

int main() {
#ifdef _DEBUG
	freopen("779d0.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string a, b;
	cin >> a >> b;
	int n = a.size(), k;
	int m = b.size();

	vector<int> perm(n);
	for (int i = 0; i < n; i++) {
		cin >> k;
		perm[i] = k - 1;
	}

	/*
	 * Fail: char 배열 추가로 빠른 detection 은 불가.
	 *
	 * 뒤에서 부터 들어오는 random 위치의 char 배열이 하나씩 추가 될때,
	 * kmp 사촌으로 subsquence 존재여부를 빠르게 알 수 있나?
	 * 우선 지금 지식으로는 불가능.
	 * 그럼 다른 방식을 찾아야함.
	 * 10만을 binary search로 뛰어가며 존재 여부를 검사하면 됨
	 *
	 * st, ed 는 그려보면,
	 * st-----------------ed
	 * 111111111100000000000
	 */

	auto check = [&](int k) {
		int ai = 0, bi = 0;
		vector<bool> use(n, true);
		for (int i = 0; i < k; i++)
			use[perm[i]] = false;
		while (ai < n && bi < m) {
			if (use[ai] && a[ai] == b[bi])
				bi++;
			ai++;
		}
		return bi == m;
	};
	/* test
	 * 110
	 * st = 0, ed = 2, mid = 1
	 * st = 1, ed = 2, mid = 2
	 * st = 1, ed = 1
	 *
	 * test2
	 * 1110000
	 * st = 0, ed = 6, mid = 3
	 * st = 3, ed = 6, mid = 5
	 * st = 3, ed = 4, mid = 4 
	 */
	auto st = 0, ed = n-1;
	while (st < ed) {
		auto mid = st + (ed - st + 1)/2;
		if (check(mid)) 
			st = mid;
		else 
			ed = mid - 1;
	}
	int mid = -1;
	if (check(st))
		mid = st;
	cout << mid << endl;
		
	return 0;
}
