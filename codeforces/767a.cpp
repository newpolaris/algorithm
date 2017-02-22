#include <iostream>
#include <queue>
#include <algorithm>

#define ALL(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define SZ(x) (int((x).size()))

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("767a0.in", "r", stdin);
#endif
	int n, a;
	cin >> n;
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

}
