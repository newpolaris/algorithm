#include <iostream>
#include <vector>
#include <string>
#include <string.h>

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

vector<int> coins = { 1, 5, 10, 20, 50 };
int cache[10000];

int exchangeCount(int remain) {
	if (remain < 0) return 0;
	if (remain == 0) return 1;
	auto& ret = cache[remain];
	if (ret != -1) return ret;
	ret = 0;
	for (auto c : coins) {
		ret += exchangeCount(remain - c);
	}
	return ret;
};

int main() {
#ifdef _DEBUG
	freopen("coinexchange0.in", "r", stdin);
#endif
	int n, k;
	cin >> n;
	memset(cache, -1, sizeof(cache));
	while (n--) {
		cin >> k;	
		cout << exchangeCount(k) << endl;
	}
	return 0;
}
