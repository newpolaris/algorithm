#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>

using namespace std;

using ll=long long;

const int MAX_N = 12;
int cnt[1 << MAX_N*2];
int n;

int incr(int a) {
	if (a > 0) return a+1;
	else return a-1;
}

int bfs(int here, int goal) {
	queue<int> q;
	q.push(here);
	q.push(goal);
	cnt[here] = 1;
	cnt[goal] = -1;
	while (!q.empty()) {
		auto v = q.front();
		q.pop();
		vector<int> top(4, MAX_N+1);
		for (int i = 0; i < n; i++) {
			auto pos = (v >> i*2) & 0x3;
			if (top[pos] > i) {
				top[pos] = i;
			}
		} <F4>
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (top[i] >= top[j]) continue;
				auto next = v;
				next &= ~(0x3 << top[i]*2);
				next |= j << top[i]*2;
				if (cnt[next] == 0) {
					cnt[next] = incr(cnt[v]);
					q.push(next);
				}
				else if (signbit(cnt[next]) != signbit(cnt[v])) {
					return abs(cnt[next]) + abs(cnt[v]) - 1;
				}
			}
		}
	}
	return -1;
}

int main() {
#ifdef _DEBUG
	freopen("hanoi4.in", "r", stdin);
#endif
	int c, k, a;	
	cin >> c;
	while (c--) {
		memset(cnt, 0, sizeof(cnt));
		cin >> n;
		int v = 0;
		for (int i = 0; i < 4; i++) {
			cin >> k;
			for (int j = 0; j < k; j++) {
				cin >> a;
				a--;
				v |= i << a*2;
			}
		}
		int goal = 0;
		for (int i = 0; i < n; i++) {
			goal |= 0x3 << i*2;
		}
		cout << bfs(v, goal) << endl;
	}

	return 0;
}
