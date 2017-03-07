#include <iostream>
#include <queue>
#include <functional>

#define x first
#define y second
#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("782a0.in", "r", stdin);
#endif
	int n, a;
	scanf("%d", &n);
	n *= 2;
	int cnt = 0;
	int maxcnt = 0;
	vector<int> sock(100001, 0);
	while (n--) {
		scanf("%d", &a);
		if (sock[a]) {
			sock[a]--;
			cnt--;
		} else {
			sock[a]++;
			cnt++;
			maxcnt = max(cnt, maxcnt);
		}
	}
	printf("%d\n", maxcnt);
	return 0;
}
