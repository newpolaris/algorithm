#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string.h>

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

using namespace std;

const int maxn = 100001;
using ll = long long;
const ll inf = 1e18;
ll dp[maxn][3];
ll a[maxn][3];
ll colsum[maxn];
int n;

// 돌아간다는 연산을 버리고 모든 가능한 path 를 generate 하면 된다.
ll path(int r, int c) {
	if (c > n) 
		return -inf;
	if (c == n)
		return (r == 2) ? 0 : -inf;

	ll& ret = dp[c][r];
	if (ret != -1)
		return ret;

	ret = -inf;

	/* generate all path */
	// simple (c fixed, r change) after increase c+1
	ll coladd = 0;
	REP(i, r, 3) { // 단순 오른쪽 1칸, 아래로 여러칸 후 오른쪽 1칸
		coladd += a[c][i];
		ret = max(ret, path(i, c+1)+coladd);
	}
	coladd = 0;
	for (int i = r; i >= 0; i--) { // 단순 오른쪽 1칸, 위로 여러칸 후 오른쪽 1칸
		coladd += a[c][i];
		ret = max(ret, path(i, c+1)+coladd);
	}

	// cover path that can't handle in above case
	// https://s29.postimg.org/6nb8g5u6f/20170126_161450.jpg
	// 위에 걸로 대부분 방향을 generate 가능하나, 0 혹은 2 위치에서
	// 'ㄹ' 모양으로 움직이면 'r' 이 뒤집힌다.
	// 이러한 'ㄹ' 자 움직임은 2칸이상이면 자유롭게 움직일 수 있다.
	// 1칸은 위의 단순 case 로 인해 방향 바꾸는 연산이 커버되므로
	// 일반적인 2칸의 경우만 처리하면 2+2 는 4칸, 2+1은 3칸 이런식으로
	// 알아서 커버 된다.
	if (r != 1 && c+1 < n) {
		ret = max(ret, path(r == 0 ? 2 : 0, c+2) + colsum[c] + colsum[c+1]);
	}

	return ret;
}

int main() {
#ifdef _DEBUG
	freopen("762d.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	REP(j, 0, 3)
		REP(i, 0, n)
			cin >> a[i][j];

	REP(i, 0, n) 
		colsum[i] = a[i][0]+a[i][1]+a[i][2];

	memset(dp, -1, sizeof(dp));
	cout << path(0, 0) << endl;

	return 0;
}
