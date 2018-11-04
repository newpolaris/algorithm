#include <iostream>
#include <queue>
#include <algorithm>

#define all(x) (x).begin(), (x).end()
#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define sz(x) (int((x).size()))

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("767a0.in", "r", stdin);
#endif
	int n, a;
	cin >> n;
	// 꼭 PQ 가 필요한가?
#if _OLD
	priority_queue<int> que;
	int cur = n;
	REP(i, 0, n) {
		cin >> a;
		que.push(a);
		while (!que.empty() && que.top() == cur) {
			que.pop();
			cout << cur-- << " ";
		}
		cout << endl;
	}
#endif
	static bool was[100001];
	int pos = n;
	forn (i, 0, n) {
		cin >> a;
		was[a] = true; 
		while (pos > 0 && was[pos]) { 
			cout << pos << " ";
			pos--;
		}
		cout << endl;
	}
	return 0;
}
