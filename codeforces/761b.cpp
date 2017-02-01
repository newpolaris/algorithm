#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <limits>

#define ALL(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define SZ(x) (int((x).size()))

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("761b0.in", "r", stdin);
#endif
	int n, L;
	cin >> n >> L;
	vector<int> a(n), b(n);
	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;
	// LCS
	vector<int> da, db;
	for (int i = 0; i < n-1; i++) 
		da.push_back(a[i+1] - a[i]);
	da.push_back(L + a[0] - a[n-1]);
	
	for (int i = 0; i < n-1; i++) 
		db.push_back(b[i+1] - b[i]);
	db.push_back(L + b[0] - b[n-1]);

	auto test = [&](int i) {
		for (int j = 0; j < SZ(b); j++) {
			if (da[(i+j)%n] != db[j])
				return false;
		}
		return true;
	};
	bool bSuc = false;
	for (int i = 0; i < SZ(a); i++) {
		bSuc = test(i);
		if (bSuc) break;
	}
	cout << (bSuc ? "YES" : "NO") << endl;
}
