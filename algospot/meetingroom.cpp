#include <iostream>
#include <vector>
#include <stack>
#include <iterator>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define x first
#define y second

using namespace std;

/*
 * 5번째:
 * 2
 * 1 20 40 50
 * 5 45 10 40
 *
 * (0-> -3 -> 2 -> -1 -> 0) -> (-2 -> 3 -> -0 -> 1 -> -2)
 * 추가로 (2 -> -0) 는 이어져서 symmetric 하다
 *
 * 앞에걸 true로 가정한다면, -3 == true, 3 == true 가 되어 망함.
 * false로 가정해야 명제가 성립. false -> (true || false)
 */
class TarjanSCC
{
public:
	vector<int> sccId;
	vector<int> discovered;
	stack<int> st;
	int sccCounter, vertexCounter;
	vector<vector<int>>& adj;

public:
	TarjanSCC(vector<vector<int>>& a) : adj(a) {}
	int scc(int here) {
		int ret = discovered[here] = vertexCounter++;
		// 스택에 here 를 넣는다. here 의 후손들은 모두 스택에서 here 후에 들어간다.
		st.push(here);  
		for(int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i];
			// (here,there) 가 트리 간선 (번저 발견된 정점으로 가는 역방향 간선 검사)
			if(discovered[there] == -1) 
				ret = min(ret, scc(there));
			// there가 무시해야 하는 교차 간선이 아니라면 (아직 묶여 있지 않은 정점으로 가는 교차)
			else if(sccId[there] == -1)
				ret = min(ret, discovered[there]);
		}  
		// here에서 부모로 올라가는 간선을 끊어야 할지 확인한다
		if(ret == discovered[here]) {
			// here 를 루트로 하는 서브트리에 남아 있는 정점들을 전부 하나의 컴포넌트로 묶는다
			while(true) {
				int t = st.top();
				st.pop();
				sccId[t] = sccCounter;
				// here  까지 정리
				if(t == here) break;
			}
			++sccCounter;
		}
		return ret;
	}
	// tarjan 의 SCC 알고리즘
	vector<int> solve() {
		// 배열들을 전부 초기화
		sccId = discovered = vector<int>(adj.size(), -1);
		// 카운터 초기화
		sccCounter = vertexCounter = 0;
		// 모든 정점에 대해 scc() 호출
		for(int i = 0; i < adj.size(); i++) if(discovered[i] == -1) scc(i);
		return sccId;
	}
};

// 두 구간 a와 b가 서로 겹치지 않는지를 확인한다.
bool disjoint(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second <= b.first || b.second <= a.first;
}

// meetings[]가 각 팀이 하고 싶어하는 회의 시간의 목록일 때, 이를
// 2-SAT문제로 변환한 뒤 함의 그래프를 생성한다.
// i번 팀은 meetings[2 * i] 혹은 meetings[2 * i + 1]중 하나 시간에 회의실을 써야 한다.
vector<vector<int>> makeGraph(const vector<pair<int, int>>& meetings) {
	int mtSize = meetings.size();
	vector<vector<int>> adj(mtSize*2);
	for (int i = 0; i < mtSize; i += 2) {	//한번에 두 회의씩 처리
		//각 팀은 i번 회의나 j번 회의 둘 중 하나는 해야 한다.
		int j = i + 1;
		adj[i * 2 + 1].push_back(j * 2); // ~i => j
		adj[j * 2 + 1].push_back(i * 2); // ~j => i

	}
	// 2중for문 역삼각 조회(내가 지은 말)!!!! 아.. 삼각 조회네...
	for (int i = 0; i < mtSize; ++i) { 
		for (int j = 0; j < i; ++j) {
			//i번 회의와 j번 회의가 서로 겹칠 경우
			if (!disjoint(meetings[i], meetings[j])) {
				//i번 회의가 열리지 않거나, j번 회의가 열리지 않아야 한다.
				//(~i or ~j) 절을 추가한다.
				adj[i * 2].push_back(j * 2 + 1); // i => ~j
				adj[j * 2].push_back(i * 2 + 1); // j => ~i
			}
		}
	}
	return adj;
}

vector<int> Solve2Sat(vector<int> sccId) {
	int v = sccId.size() / 2;
	vector<int> select(v);
	for (int i = 0; i < 2*v; i += 2)
		if (sccId[i] == sccId[i + 1])
			return vector<int>();
	for (int i = 0; i < v; ++i) {
		// -a가 a보다 높다면, -a -> a 가 온다는 것이고, -a가 false라 봐야 명제가 풀리므로,
		// 0은 false로 -a 선택한다는것
		// 1은 true 로 a 선택한다는것
		select[i] = sccId[2*i] < sccId[2*i+1];
	}
	return select;
}

int main() {
#ifdef _DEBUG
	freopen("algospot/meetingroom.in", "r", stdin);
#endif
	int n, cases;
	cin >> cases;
	forn (c, 0, cases) {
		cin >> n;
		vector<pair<int,int>> meetings(2*n);
		forn(i, 0, 2*n) 
			cin >> meetings[i].x >> meetings[i].y;

		auto adj = makeGraph(meetings);
		TarjanSCC scc(adj);
		auto sccIdx = scc.solve();
		// 첫번째 회의를 선택하냐, 아니면 2번째를 선택하냐
		auto isSelect = Solve2Sat(sccIdx);

		if (isSelect.empty()) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			cout << "POSSIBLE" << endl;
			// 각 팀이 회의할 수 있는 시간을 출력한다
			for (int i = 0; i < 2*n; i += 2) {
				if(isSelect[i] == 1) 
					cout << meetings[i].first << " " << meetings[i].second << endl;
				else
					cout << meetings[i+1].first << " " << meetings[i+1].second << endl;
			}
		}
	}
	return 0;
}
