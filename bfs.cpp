#include <iostream>
#include <queue>

using namespace std;

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define fori(i, a, b) for (int i = (a), i##_end_ = (b); i > i##_end_; --i)
#define x first
#define y second 

/*
 * BFS에 왜 PQ를 쓸려고 했나
 * 루핑 안돌려면, 뽑고 버리고 체크해야된다.
 * 메모리 터지거, 타임오버나거나
 */
int main() {
#ifdef _DEBUG
	freopen("../baekjoon/2178.in", "r", stdin);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	int maze[101][101];
	char tmp[101];
	forn(i, 0, n) {
		scanf("%s", tmp);
		forn(j, 0, m) maze[i][j] = tmp[j] != '0'; 
	}
	queue<pair<int,pair<int,int>>> que;
	que.push({1, {0, 0}});
	while (!que.empty()) {
		auto q = que.front();
		auto l = q.x, x = q.y.x, y = q.y.y;
		que.pop();

		// TODO: 이게 없으면 루핑
		if (!maze[y][x])
			continue;

		// visit 설정
		maze[y][x] = 0;
		if (y == n-1 && x == m-1) {
			cout << l << endl;
			break;
		}
		vector<pair<int,int>> ds = {{-1,0}, {1,0}, {0,-1}, {0,1}};
		for (auto d : ds) {
			auto nx = x + d.x, ny = y + d.y;
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (maze[ny][nx]) {
				que.push({l+1, {nx, ny}});
			}
		}
	}
	return 0;
}
