#include <vector>
#include <cstdio>
#include <algorithm>
#include <stack>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)

using namespace std;

vector<vector<int>> adj;

/*
 * tarjan scc solver 
 *
 * 주어진 그래프를 SCC로 분할하는 간단한 방법은 모든 정점에서
 * 한 번씩 깊이 우선 탐색을 수행하는 것입니다. 그러면 모든
 * 정점 쌍에 대해 양방향 경로가 모두 있는지 쉽게 확인할 수 
 * 있지요. 하지만 이런 방법은 O(|V|×|E|) 시간을 필요로 하기
 * 때문에 그래프가 커질 경우 사용할 수 없습니다.
 */

// type1: algospot's solver
// 각 정점의 컴포넌트 번호. 컴포넌트 번호는 0 부터 시작하며, 
// 같은 강결합 컴포넌트에 속한 정점들의 컴포넌트 번호가 같다.
class TarjanSCC
{
public:
	// 각 정점의 컴포넌트 번호. 컴포넌트 번호는 0 부터 시작하며, 
	// 같은 강결합 컴포넌트에 속한 정점들의 컴포넌트 번호가 같다.
	vector<int> sccId;
	// 각 정점의 발견 순서
	vector<int> discovered;
	// 정점의 번호를 담는 스택
	stack<int> st;
	int sccCounter, vertexCounter;
	vector<vector<int>>& adj;

public:
	TarjanSCC(vector<vector<int>>& a) : adj(a) {}

	// here를 루트로 하는 서브트리에서 역방향 간선이나 교차 간선을
	// 통해 갈 수 있는 정점 중 최소 발견 순서를 반환한다. 
	// (이미 SCC로 묶인 정점으로 연결된 교차 간선은 무시한다)
	int scc(int here) {
		int ret = discovered[here] = vertexCounter++;
		// 스택에 here 를 넣는다. here 의 후손들은 모두 스택에서 here 후에 들어간다.
		st.push(here);  
		for(int i = 0; i < adj[here].size(); ++i) {
			/*
			 * 이제 트리 간선 (u,v)를 끊을 수 없는 경우가 언제인지 알 수 있습니다.
			 * v를 루트로 하는 서브트리에서, v보다 먼저 발견된 정점으로 가는 역방향 간선이
			 * 있다면 (u,v)를 끊어선 안 됩니다. 그런 역방향 간선이 없다고 해도, v보다 먼저 
			 * 발견되었으면서 아직 SCC로 묶여 있지 않은 정점으로 가는 교차 간선이 있다면 
			 * (u,v)를 끊어선 안 됩니다.
			 * 또 하나 눈여겨볼 만한 부분은 scc() 내에서 역방향 간선, 순방향 간선, 그리고
			 * SCC로 묶이지 않은 교차 간선 간의 구분을 하지 않은 것입니다.
			 * 각 경우에 필요한 동작들을 살펴 보면 이들을 서로 구분할 필요가 없다는 것을
			 * 쉽게 알 수 있습니다.
			 */
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
	/*
	 * tarjan 의 SCC 알고리즘
	 * DFS 방문 순서대로 발견되는 SCC 번호를 오름차순으로 매겼으니,
	 * 그 번호를 역순으로 방문하면 SCC 단위 위상 정렬 순서대로 방문하는 꼴이 되는 셈입니다.
	 */
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

int main()
{
#ifdef _DEBUG
	freopen("2150.in", "r", stdin);
#endif

	int v, e, a, b;
	scanf("%d%d", &v, &e);
	adj.assign(v, vector<int>());
	forn(i, 0, e) {
		scanf("%d%d", &a, &b);
		a--, b--;
		adj[a].push_back(b);
	}
	TarjanSCC scc(adj);

	auto id = scc.solve();
	auto k = *max_element(id.begin(), id.end()) + 1;
	vector<vector<int>> sol(k);
	forn(i, 0, v)
		sol[id[i]].push_back(i+1);
	for (auto& s : sol) sort(s.begin(), s.end());
	sort(sol.begin(), sol.end());
	for (auto& s : sol) s.push_back(-1);
	printf("%d\n", k);
	for (auto& s : sol) {
		for (auto& e : s) 
			printf("%d%c", e, " \n"[e == -1]);
	}

	return 0;
}

#ifdef _KOSARAJU
/*
 * https://blog.qwaz.io/problem-solving/scc%EC%99%80-2-sat
 * 코사라주의 알고리즘(Kosaraju’s Algorithm)
 *
 * 코사라주의 알고리즘은 다음과 같이 동작합니다.
 *
 * 1. 방향 그래프 G, 빈 스택 S, G의 간선 방향을 뒤집은 역방향 그래프 G’를 준비합니다.
 * 2. G에서 아직 방문되지 않은 정점들에 대해 DFS를 시행하고, 각 정점의 탐색이 끝나는 순서대로 S에 넣습니다.(위상정렬) 스택에 모든 정점이 들어갈 때까지 반복합니다.
 * 3. S가 빌 때까지 다음을 반복합니다.
 * 4. S의 가장 위쪽에 있는 정점 v를 뽑습니다. v가 G’에서 이미 방문된 정점이라면 정점을 다시 뽑습니다.
 * 5. G’에서 v에서 DFS를 시행해 이번 시도에 처음 방문한 정점들을 v와 같은 SCC로 묶습니다.
 * 코사라주의 알고리즘은 정방향 그래프와 역방향 그래프가 동일한 SCC를 가진다는 점을 이용합니다. 정방향 DFS를 통해 정점들을 위상정렬하고, 역방향 DFS에서 SCC를 찾는다고 생각할 수 있습니다.
 */
#include 
#include 
#include 
#include 
 
using namespace std;
const int MAX = 10020;
 
int V, E;
vector < int > front[MAX], rev[MAX];
 
void input() {
	scanf("%d%d", &V, &E);
 
	// 그래프 초기화
	for (int i = 0; i < E; i++) {
		int f, s;
		scanf("%d%d", &f, &s);
		front[f].push_back(s);
		rev[s].push_back(f);
	}
}
 
int visited[MAX], stack[MAX], top;
vector < vector < int > > sccGroup;
 
void front_dfs(int node) {
	visited[node] = 1;
	for (auto next : front[node]) {
		if (!visited[next]) {
			front_dfs(next);
		}
	}
	// DFS를 빠져 나올 때 스택에 쌓음
	stack[top++] = node;
}
 
void rev_dfs(int node) {
	visited[node] = 1;
	// 마지막 그룹에 정점 추가
	sccGroup[sccGroup.size()-1].push_back(node);
	for (auto next : rev[node]) {
		if (!visited[next]) {
			rev_dfs(next);
		}
	}
}
 
void solve() {
	// 위상 정렬
	for (int v = 1; v <= V; v++) {
		if (!visited[v]) {
			front_dfs(v);
		}
	}
 
	// 그룹 묶기
	memset(visited, 0, sizeof(visited));
	while (top) {
		int node = stack[top-1];
		top--;
		if (!visited[node]) {
			// 빈 그룹 추가
			sccGroup.push_back(vector < int >());
			rev_dfs(node);
		}
	}
 
	// 문제 요구 조건대로 정렬
	for (auto &vec : sccGroup)
		sort(vec.begin(), vec.end());
	sort(sccGroup.begin(), sccGroup.end());
 
	// 출력
	printf("%d\n", sccGroup.size());
	for (auto &vec : sccGroup) {
		for (auto elem : vec) {
			printf("%d ", elem);
		}
		puts("-1");
	}
}
 
int main() {
	input();
 
	solve();
 
	return 0;
}
#endif
