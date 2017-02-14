#include <iostream>
#include <string>
#include <string.h>
#include <iostream>
#include <regex>
#include <cassert>
#include <map>
#include <set>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define x first
#define y second

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("765c1.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
	int k, a, b;
	cin >> k >> a >> b;
	/* 
	 * Hacking 당함. 최대 값 자체는 맞음.
	 * 양쪽이 0인 경우 예외처리도 함 남은 경우는?
	 *
	 * 문제는 경기가 한쪽이 0이면 다른 한쪽은 어떤 수가 나와야 경기가 끝날까?
	 */
	int ans = a/k + b/k;
	if (a / k == 0 && b % k != 0) ans = -1;
	if (b / k == 0 && a % k != 0) ans = -1;
	cout << ans << endl;

	return 0;
}
