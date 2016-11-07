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

int shiftor(int a, int b, int i) {
	return a | (b << i*2);
}

// 2 bit clear and bitwise or
int shiftset(int a, int b, int i) {
	return (a & ~(0x3 << i*2)) | (b << i*2);
}

// 2 bit get
int shiftget(int a, int i) {
	return (a >> i*2) & 0x3;
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
			auto pos = shiftget(v, i);
			if (top[pos] > i) {
				top[pos] = i;
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (top[i] >= top[j]) continue;
				auto next = shiftset(v, j, top[i]);
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
		// 뒤집어서 마지막 목표 상태를 0 으로 해도 되돌록.
		for (int i = 3; i >= 0; i--) {
			cin >> k;
			for (int j = 0; j < k; j++) {
				cin >> a;
				v = shiftor(v, i, a-1);
			}
		}
		cout << bfs(v, 0) << endl;
	}

	return 0;
}
