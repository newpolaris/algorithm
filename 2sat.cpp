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
#ifdef _WRONG
	// 실제론 i 번 하지 않으면 i+1을 해야하므로, 줄일 수 있을 것 같지만,
	// 겹치는 부분 기술할 때, 잘못된 조건이 추가된다.
	// node가 4개이므로 표현력이 준다. 그림이, (-0 -> -1) -> (0 -> 1) 
	vector<vector<int>> adj(mtSize);
	for (int i = 0; i < mtSize; ++i) { 
		for (int j = 0; j < i; ++j) {
			// i번 회의와 j번 회의가 서로 겹칠 경우
			if (!disjoint(meetings[i], meetings[j])) {
				// i번 회의가 열리지 않거나, j번 회의가 열리지 않아야 한다.
				// (~i or ~j) 절을 추가한다.
				adj[i^1].push_back(j); // i => ~j
				adj[j^1].push_back(i); // j => ~i
			}
		}
	}
#endif
	return adj;
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
		auto isSelect = scc.Solve2Sat(sccIdx);

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

/*
 * https://blog.qwaz.io/problem-solving/scc%EC%99%80-2-sat
 *
 * 이렇게 그래프를 생성하면 or로 묶인 두 개의 변수 중 적어도 하나는 참이어야 하기 때문에, A에서 B로 가는 간선은 A가 참이라면 B도 반드시 참이라는 것을 의미하게 됩니다. 이제 이 그래프에 SCC 알고리즘을 적용해서 정점들을 컴포넌트로 묶은 이후를 생각해봅시다. SCC의 정의와 간선을 그은 조건 때문에, 컴포넌트 내에 하나의 정점이라도 참이라면 그 컴포넌트는 모두 참이 됩니다. 따라서 같은 컴포넌트에 속한 정점들은 전부 참이거나 전부 거짓이라는 것을 알 수 있습니다.

   x와 \neg x는 다음 세 가지 중 한 가지 관계를 가집니다.

   x와 \neg x가 같은 컴포넌트에 속하는 경우
   x에서 \neg x로 가는 경로(또는 \neg x에서 x로 가는 경로)만 존재하는 경우
   x와 \neg x간에 경로가 존재하지 않는 경우
   첫 번째는 답이 존재하지 않는 경우입니다. 주어진 논리식을 참으로 만드는 논리 변수 조합이 존재하는 것과, 논리 변수 \forall x에 대해 x와 \neg x 정점이 같은 컴포넌트에 속하지 않는 것이 필요충분조건임이 증명되어 있습니다.

   두 번째는 위상정렬 했을 때 더 뒤쪽에 존재하는 정점만이 참입니다. 세 번째는 둘 중 어느 것을 참으로 결정해도 상관 없습니다.

   그래프가 skew-symmetric하기 때문에 A, ~B가 같은 컴포넌트에 속한다면 \neg A, ~\neg B 또한 같은 컴포넌트에 속하고, 이 특징을 이용해 위의 성질들을 증명할 수 있습니다.

   위의 성질들을 이용해 각 논리 변수의 값을 다음 방법으로 찾을 수 있습니다.

   논리식에서 그래프를 생성합니다.
   생성된 그래프에 SCC 알고리즘을 적용합니다.
   만약 x와 \neg x의 SCC 번호가 같은 정점이 존재한다면 주어진 논리식을 만족하는 조합은 존재하지 않습니다.
   아니라면, x의 SCC 번호가 \neg x의 SCC 번호보다 작은 경우 x가 참입니다.

   두번째 경우에 대한 근거:

   여튼 여기서 주목해야 할 점은, p → q라는 명제가 있을 때 p가 거짓이면 q는 참이어도 거짓이어도 명제를 해치지 않지만, p가 참이면 q도 반드시 참이어야 합니다.
   따라서 하나의 SCC 안에 있는 정점들은 그 중 하나라도 참이면 나머지도 모두 참이어야 하고,
   따라서 SCC 안에 p와 ¬p가 동시에 존재한다면 둘 다 참일 수는 없으므로 모순이 됩니다.
   
   그러므로,

   그럼 이제 나아가서, 각 변수에 어떤 값을 대입해야 f 식을 참으로 만들 수 있는지까지 알아봅시다.
   이 솔루션을 얻어낼 수 있다면, f 식을 참으로 만들 수 있는지에 대한 조건이 정당하다는 것도 증명해낼 수 있겠죠.

   아이디어는 아까 언급한대로, 명제 p → q가 있을 때 p가 거짓이라면 절대 이 명제를 해칠 일이 없다는 것에서 나옵니다.
   이제 SCC 단위로는 안의 정점들이 다 같은 값을 가져야 한다는 것을 알았으니, 각 SCC를 하나의 정점으로 본다면 이런 발상이 가능합니다.
   SCC P, Q가 있을 때, P에서 Q로 가는 경로가 존재한다면, 만약 P의 정점들의 값이 거짓이라면 Q는 어찌되더라도 좋지만, P의 정점들의 값이 참이었다면 Q에 속한 정점들의 값은 무조건 참이어야만 합니다.

   따라서 SCC 단위로 위상 정렬을 하여 훑어갈 때, 처음에 만나는 정점들의 값은 되도록 false로 설정해주고, 그 not 버젼의 정점을 true가 되게 하는 식으로 설정해 봅시다.
   q = ¬p라 할 때, p가 먼저 방문되었을 경우 p를 false로, q를 true로 설정하는 식으로 하면,
   p와 q는 서로 다른 SCC에 있고, p가 속한 SCC를 P, q가 속한 SCC를 Q라 하면 P에서 Q로 가는 경로야 있을 수 있지만 Q에서 P로 가는 경로는 없으므로 이런 방식이 먹힙니다. 즉, 이런 방식으로 값을 매기다가 참->거짓 꼴의 이동경로가 생기지 않습니다.

   가능성 판별 후, 이런 추가적인 작업을 행해 주면 되는데,
   여기서 SCC DAG의 위상 정렬 순서대로 정점을 방문하는 것을 놀랍도록 빠르게 할 수 있는데
   종만북에서 언급한 위상 정렬 알고리즘이 DFS 방문 후 그 순서를 역순으로 뒤집으면 위상 정렬 순서가 되는 것이었습니다.
   DFS 방문 순서대로 발견되는 SCC 번호를 오름차순으로 매겼으니, 그 번호를 역순으로 방문하면 SCC 단위 위상 정렬 순서대로 방문하는 꼴이 되는 셈입니다.
   이제 만나는 변수마다 먼저 마주친 쪽을 false로 설정해주면 되는데, 정점 x_k를 먼저 마주쳤다면 x_k = false가 되고, 정점 not x_k를 먼저 마주쳤다면 x_k = true가 됩니다.
   또한, SCC 번호 순으로 변수를 방문하므로 하나의 SCC 안에 속한 변수들은 모두 연속적으로 방문되므로 항상 같은 값으로만 설정될 겁니다.

*/
#ifdef _
    int result[MAX]; // 각 변수의 값 (0, 1 중 하나)
    memset(result, -1, sizeof(result)); // 초기화
    // 각 변수를 속해있는 SCC 번호순으로 정렬
    P p[MAX*2];
    for(int i=0; i<N*2; i++)
        p[i] = P(sn[i], i);
    sort(p, p+N*2);
 
    // 놀랍게도, SCC 번호가 크면 클수록 DAG상에서 앞에 있음
    for(int i=N*2-1; i>=0; i--){
        int var = p[i].second;
        // 아직 해당 변수값이 설정되지 않았다면 지금 설정
        if(result[var/2] == -1) result[var/2] = !(var%2);
    }
    // 각 변수의 값 출력
    for(int i=0; i<N; i++)
        printf("%d ", result[i]);
#endif
#ifdef _

/* [a, -a] 
 * 0은 false로 -a 선택한다는것
 * 1은 true 로 a 선택한다는것
 */
vector<int> Solve2Sat(int v, vector<int> sccId){
	// 함의 그래프의 정점들을 강결합 요소별로 묶는다.
	// 이 SAT문제를 푸는 것이 불가능한지 확인한다. 한 변수를 나타내는 두 정점이
	// 같은 강결합 요소에 속해 있을 경우 답이 없다.
	for (int i = 0; i < 2*V; i += 2)
		if (sccId[i] == sccId[i + 1])
			return vector<int>();

	// SAT 문제를 푸는 것이 가능하다. 답을 생성하자!
	vector<int> value(v, -1); 
	// Tarjan 알고리즘에서 SCC번호는 위상 정렬의 역순으로 배정된다 (높을 수록 먼저옴(root 에 가깝다))
	// SCC 번호의 역순으로 각 정점을 정렬하면 위상 정렬 순서가 된다.
	vector<pair<int, int> > order;
	for (int i = 0; i < 2 * v; ++i)
		order.push_back(make_pair(-sccId[i], i));
	sort(order.begin(), order.end());

	// 각 정점에 값을 배정한다
	for (int i = 0; i < 2 * v; ++i) {
		int vertex = order[i].second;
		int variable = vertex / 2;

		if (value[variable] != -1) continue;
		//not A가 A보다 먼저 나왔으면 A는 참
		//A가 not A보다 먼저 나왔으면 A는 거짓
		int isTrue = !((vertex % 2) == 0);	
		value[variable] = isTrue;
	}
	return value;
}
#endif
#ifdef _
/*
 * 어짜피 답이 있다면, 2개중 하나를 선택해야하는 것
 * sccId[i] != sccId[i+1] 이 필요 충분 조건이라고 하니,
 * (첫 번째는 답이 존재하지 않는 경우입니다.
 *  주어진 논리식을 참으로 만드는 논리 변수 조합이 존재하는 것과,
 *  논리 변수 \forall x에 대해 x와 \neg x 정점이 같은 컴포넌트에
 *  속하지 않는 것이 필요충분조건임이 증명되어 있습니다)
 * 결국 두 숫자는 다를 꺼고, 그 경우 root -> child -> 식으로 위상 정렬 되었을 때,
 * 뒤에 있는 걸 참으로 보면된다,
 */
vector<int> Solve2Sat(int v, vector<int> sccId) {
	vector<int> select(v);
	for (int i = 0; i < 2*v; i += 2)
		if (sccId[i] == sccId[i + 1])
			return vector<int>();
	for (int i = 0; i < v; ++i) {
		// -a가 a보다 높다면, -a -> a 가 온다는 것이고, -a가 false라 보면 된다는 것
		// 0은 false로 -a 선택한다는것
		// 1은 true 로 a 선택한다는것
		select[i] = sccId[2*i] < sccId[2*i+1];
	}
	return select;
}
#endif
