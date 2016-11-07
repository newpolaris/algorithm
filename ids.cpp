#include <map>
#include <vector>

using namespace std;

// 15-퍼즐 문제의 상태를 표현하는 클래스
class State;
class State {
public:
	// 인접한 생태들의 목록을 반환한다.
	vector<State> getAdjacent() const;
	// map에 State 를 넣기 위한 비교 연산자
	bool operator < (const State& rhs) const;
	// 종료 상태와 비교하기 위한 연산자
	bool operator == (const State& rhs) const;
};
typedef map<State, int> StateMap;


int best;
// 깊이 우선 탐색
void dfs(State here, const State& finish, int steps) {
	// 지금까지 구한 최적해보다 더 좋은 가능성이 없다면 버린다.
	if (steps >= best) return;
	// 목표 상태에 도달한 경우
	if (here == finish) {
		best = steps;
		return;
	}

	// 인접 상태들을 깊이 우선 탐색으로
	vector<State> adjacent = here.getAdjacent();
	for (int i = 0; i < adjacent.size(); ++i) {
		dfs(adjacent[i], finish, steps+1);
	}
}

// 점점 깊어지는 탐색
int ids(State start, State finish, int growthStep) {
	for (int limit = 4; ; limit += growthStep) {
		best = limit + 1;
		dfs(start, finish, 0);
		if (best <= limit) return best;
	}
	return -1;
}
