#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <numeric>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define fori(i, a, b) for (int i = (a), i##_end_ = (b); i > i##_end_; --i)
#define all(x) (x).begin(), (x).end()

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("2156.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	/*
	 * 연속 마시는 것에서 0잔은 없다, 1,2를 하고 한칸 뛰워서 1로 시작이다
	 * c[k+2][1] = c[k][1] + a[k+2]
	 * c[k+2][1] = c[k][2] + a[k+2]
	 * c[k+1][2] = c[k][1] + a[k+1]
	 *
	 * 모두 0 이상일 것이므로, 2개 이상 뛰워야 할 필요는 없다 
	 * 4 5 1 1 16 15
	 */
#if _OLD
	vector<int> cup(n+4);
	for (int i = 1; i <= n; i++) cin >> cup[i];
	int c[10004][3], goal = 0;
	memset(c, 0, sizeof(c));
	c[1][1] = cup[1];
	c[2][1] = cup[2];
	c[3][1] = cup[3];
	for (int i = 1; i <= n; i++) {
		c[i+2][1] = max(c[i+2][1], c[i][1] + cup[i+2]);
		c[i+2][1] = max(c[i+2][1], c[i][2] + cup[i+2]);
		c[i+3][1] = max(c[i+3][1], c[i][1] + cup[i+3]);
		c[i+3][1] = max(c[i+3][1], c[i][2] + cup[i+3]);
		c[i+1][2] = max(c[i+1][2], c[i][1] + cup[i+1]);
		goal = max(c[i][1], goal);
		goal = max(c[i][2], goal);
	}
	cout << goal << endl;
#endif

	/*
	 * Fail : 틀림 (3칸 점프해야함) 
	 * Ex:    4 5 1 1 6 9
	 *
	 * 연속 3칸은 마실수 없는 제약
	 * 2579 한번에 1칸, 2칸 오를수 있는 제한이 있는 경우 
	 * 2156 제한은 없지만 최대한 많이 마셔야 하는 경우 (3칸 점프 가능)
	 *
	 * a b c d e f
	 * 4 5 1 1 6 7

	 * f 에서 봐야할 모든 경우의 수:
	 * c[f] = 7 + max(a[e]+c[c], c[d], c[b]+a[e])
	 * (d,f), (c,e,f), (b,e,f)
	 */
#ifdef _OLD
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	int c[10001];
	c[0] = a[0];
	c[1] = a[1]+a[0];
	c[2] = max(a[1],a[0])+a[2];
	c[3] = max(a[0]+a[2]+a[3], a[0]+a[1]+a[3]);
	for (int i = 4; i < n; i++) {
		c[i] = a[i] + max(a[i-1]+c[i-3], max(c[i-2], c[i-4]+a[i-1]));
	}
	// 6 10 13 9 8 1 의 경우 최대 값은 8 번에 위치됨
	cout << *max_element(c, c+n) << endl;
#endif
	/*
	 * 위의 코드는 a[1] 체크도 않했고, 길다. 짧게 짜려면?
	 * c[i] = max(c[i-1], c[i]) 를 넣는다면, 큰 값이 끌려려 올라간다.
	 * 여러칸 점프 가능하니 최대 값에서 점프하는것이 좋고, 항상 최대값이
	 * 유지되니 그냥 output 가능
	 */
	static int a[10001];
	for (int i = 0; i < n; i++) cin >> a[i];
	int c[10001];
	c[0] = a[0];
	c[1] = a[0] + a[1];
	// Fail: a[0]+a[2] 도 candidate 임
	c[2] = max(c[1], max(a[0]+a[2], a[1]+a[2]));
	for (int i = 3; i < n; i++) {
		c[i] = max(c[i-2], c[i-3] + a[i-1]) + a[i];
		c[i] = max(c[i-1], c[i]);
	}
	cout << c[n-1] << endl;
	return 0;
}
