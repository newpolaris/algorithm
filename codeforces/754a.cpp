#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define x first
#define y second 

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define ALL(x) (x).begin(), (x).end()

using namespace std;

int sum[101];
int n;
vector<pair<int,int>> p; 
bool split(int l, int r, int a) {
	if (sum[r]+a != 0) {
		p.push_back({l, r});
	} else {
		for (int i = r; i >= l; i--) {
			if (sum[i] != 0) {
				// reculsive는 필요치 않다. 그냥 넣어도 된다.
				// arr(l, i) + arr(i+1, r) == 0 and arr(l, i) != 0 then arr(i+1, r) != 0
				if (split(l, i, a) && split(i+1, r, a - sum[i]))
					return true;
			}
		}
		return false;
	}
	return true;
}

int main() {
#ifdef _DEBUG
	freopen("754a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
	cin >> n;
	vector<int> arr(n);
	for (auto& a : arr) cin >> a;
	sum[0] = arr[0];
	REP(i, 1, n) {
		sum[i] = sum[i-1] + arr[i];
	}
	bool ret = split(0, n-1, 0);
	if (ret == false) {
		cout << "NO" << endl;
	} else {
		sort(ALL(p));
		cout << "YES" << endl;
		cout << p.size() << endl;
		for (auto i : p) {
			cout << (i.x+1) << " " << (i.y+1) << endl;
		}
	}
}
