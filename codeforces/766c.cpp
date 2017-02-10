#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <regex>
#include <cassert>
#include <map>
#include <queue>
#include <set>

#define ALL(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define x first
#define y second

using namespace std;

int n;
string str;
vector<int> alpha(26);
const int MOD = 100000007;

int isValid(int s, int l) {
	if (l == 0 || l == n) 
		return false;
	for (int i = 0; i < l; i++) {
		char c = str[s+i];
		int idx = c-'a';
		if (alpha[idx] <= i) 
			return false;
	}
	return true;
}

int dp(int s, int l) {
	int ret = (isValid(s, l) ? 1 : 0);
	for (int i = 1; i < l; i++) {
		auto a = isValid(s, i) % MOD;
		auto b = dp(s+i, l-i) % MOD;
		ret += a*b % MOD;
	}
	return ret;
}

int main() {
#ifdef _DEBUG
	freopen("766c.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> str;
	for (auto& a : alpha)
		cin >> a;
	cout << dp(0, n) << endl;
	return 0;
}
