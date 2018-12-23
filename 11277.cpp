#include <iostream>
#include <vector>
#include <stack>
#include <iterator>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define x first
#define y second

using namespace std;

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
};

int main() {
#ifdef _DEBUG
	freopen("11277.in", "r", stdin);
#endif
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	vector<vector<int>> adj(n*2);
	auto idx = [](int k) {
		return 2*(abs(k)-1) + (k < 0);
	};
	forn(i, 0, m) {
		scanf("%d%d", &a, &b);
		adj[idx(a)^1].push_back(idx(b));
		adj[idx(b)^1].push_back(idx(a));
	}

	TarjanSCC scc(adj);
	auto sccIdx = scc.solve();
	// 첫번째를 선택하냐, 아니면 2번째를 선택하냐
	auto isSelect = scc.Solve2Sat(sccIdx);
	printf("%d\n", !isSelect.empty());
	return 0;
}
