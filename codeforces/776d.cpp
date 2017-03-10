#include <iostream>
#include <queue>
#include <functional>

#define x first
#define y second
#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

/*
 * Fail: 
 * 2개만 조재하기에, 2 SAT로 풀수도 있지만(editorial comment 참조),
 * graph coloring으로 풀 수 있다. 
 * 스위치 node로 두고 방을 edge로 둔다. 방 하나당 2개 스위치만 존재하기에,
 * 방이 OFF라 스위치를 켜야되면 1로 두고 반대편을 0으로 둬서 켯다는걸 encoding
 * 방이 ON이라면, 양쪽 1, 양쪽 0 으로 두면 됨
 * 잘 이해가 안되겠지만, 그림으로 그리면.
 *
 * 예제 2번
 * 3 3 
 * 1 0 1
 * 3 1 2 3 
 * 1 2 
 * 2 1 3
 *
 * 1---- OFF(Room.2) ----- 2
 * |
 * ㄴ---- ON(Room.1) ----- 3
 * |                       |
 * ㄴ---- ON(Room.3) ------
 *
 * 1을 0 으로 두면 2는 1, 3은 0으로 두면 성립한다
 * 1을 1 으로 두면 2는 0, 3은 1으로 두면 성립한다
 *
 * 한바퀴 돌아서 꺼꾸로 되는건 기존값과 비교해서 막는다.
 */

int n, m, x;

// door on/off
int door[100000], col[100000];
vector<int> f[100000];
vector<pair<int,int>> g[100000];

int dfs(int v, int c) {
	if (col[v] == -1) {
		col[v] = c;
	} else {
		if (col[v] != c)
			return 0;
		return 1;
	}
	for (auto to : g[v]) {
		if (!dfs(to.x, c ^ to.y))
			return 0;
	}
	return 1;
}

int main() {
#ifdef _DEBUG
	freopen("776d.in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	forn(i, 0, n) scanf("%d", door+i);
	forn(i, 0, m) {
		int cnt;
		scanf("%d", &cnt);
		forn(_, 0, cnt) {
			int x;
			scanf("%d", &x), --x;
			f[x].push_back(i);
		}
	}
	forn(i, 0, n) {
		/* 
		 * Fail: bool flag 가중치로 열결된 Graph coloring
		 *
		 * 해당 룸을 컨트롤하는 f 2개, 가중치 대신 on/off 상태를 coding 한다.
		 * 자주 쓰는 기법인 듯. 
		 * 열린 상태 1 ^ 1 = 0
		 * 닫힌 상태 0 ^ 1 = 1
		 *
		 * 1은 뒤집어 달라는 거다
		 *
		 * 0 을 기본 상태로 하여 dfs를 돌리면,
		 * 기본 생태0 & 닫힌 문1 : 0 ^ 1 = 1 (다음 기대값)
		 * 기본 생태0 & 열린 문0 : 0 ^ 0 = 0 (다음 기대값)
		 *
		 * 1 을 기본 상태로 하여 dfs를 돌리면,
		 * 기본 생태1 & 닫힌 문1 : 1 ^ 1 = 0 (다음 기대값)
		 * 기본 생태1 & 열린 문0 : 1 ^ 0 = 1 (다음 기대값)
		 */
		g[f[i][0]].pb({f[i][1], door[i] ^ 1});
		g[f[i][1]].pb({f[i][0], door[i] ^ 1});
	}
	forn(i, 0, m) col[i] = -1;
	forn(i, 0, m) if (col[i] == -1) {
		if (!dfs(i, 1)) {
			printf("%s\n", "NO");
			return 0;
		}
	}
	printf("%s\n", "YES");
	return 0;
}
