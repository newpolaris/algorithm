#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>


#define x first
#define y second
#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

#ifndef _OLD

map<string, int> city;
int cidx = 0;
int getCityIdx(string& name) {
	if (city.count(name) == 0)
		return city[name] = cidx++;
	return city[name];
}

vector<vector<int>> adj;

// 2-SAT문제로 변환한 뒤 함의 그래프를 생성한다.
// i번 팀은 names[2 * i] 혹은 names[2 * i + 1]중 하나의 팀이름을 써야 한다.
void makeGraph(int n, const vector<int>& names) {
	int mtSize = names.size();
	adj.clear();
	adj.resize(mtSize);

	/*
	 * FAIL: 2-SAT 으로 조건식을 어떻게 풀어야 하는가?
	 *
	 * Let option 1 = true, option 2 = false, 'a' and 'b' a team
	 * (-a = not a first = a second)
	 *
	 * case 1: first(a) == first(b) -> (¬a || ¬a) && (¬b || ¬b) — both second option 
	 *         즉, first(a), first(b)를 넣었을 때 && 로 연결된 boolean 집합이 망하게 되게
	 *         (둘다 no가 나와야 참이되게, (!a && !b))
	 *
	 * case 2: second(a) == second(b) -> (a || b)
	 *         둘다 second 나옴 안됨
	 * case 3: first(a) == second(b) -> (¬a || b)
	 * case 4: second(a) == first(b) -> (a || ¬b)
	 *         (a == no & b == yes) 넣으면 false가 떨어진다
	 */
	auto getfirst = [&](int i) { return names[i*2]; };
	auto getsecond = [&](int i) { return names[i*2+1]; };
    auto get_value = [&](int v){
        return 2 * (abs(v) - 1) ^ (v < 0);
    };
    // [1..n], use -a for not a
    auto add_formula = [&](int a, int b){
        a = get_value(a);
        b = get_value(b);
        adj[a^1].push_back (b);
        adj[b^1].push_back (a);
    };
    for (int i = 1; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            if (getfirst(i-1) == getfirst(j-1)){
                add_formula(-i, -i);
                add_formula(-j, -j);
            }
            if (getsecond(i-1) == getsecond(j-1)){
                add_formula(i, j);
            }
            if (getfirst(i-1) == getsecond(j-1)){
                add_formula (-i, j);
            }
            if (getsecond(i-1) == getfirst(j-1)){
                add_formula (i, -j);
            }
        }
    }
}

class TarjanSCC
{
public:
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
	// tarjan 의 SCC 알고리즘
	vector<int> solve() {
		// 배열들을 전부 초기화
		sccId = discovered = vector<int>(adj.size(), -1);
		// 카운터 초기화
		sccCounter = vertexCounter = 0;
		// 모든 정점에 대해 scc() 호출
		for (int i = 0; i < adj.size(); i++) 
			if(discovered[i] == -1) scc(i);
		return sccId;
	}
};

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

int main() {
#ifdef _DEBUG
	freopen("782d0.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	string a, b;
	cin >> n;

	vector<int> names;
	vector<string> team(2*n);
	forn(i, 0, n) {
		cin >> a >> b;
		// two candidate city name
		string n0 = a.substr(0, 3), n1 = a.substr(0, 2) + b[0];
		int i0 = getCityIdx(n0), i1 = getCityIdx(n1);
		names.push_back(i0);
		names.push_back(i1);
		team[i0] = n0;
		team[i1] = n1;
	}
	makeGraph(n, names);
	TarjanSCC scc(adj);
	vector<int> sccId = scc.solve();
	auto ret = Solve2Sat(n, sccId);
	if (ret.empty()) cout << "NO" << endl;
	else { 
		cout << "YES" << endl;
		forn (i, 0, n) {
			if (ret[i] == 1)
				cout << team[names[2*i]] << endl;
			else
				cout << team[names[2*i+1]] << endl;
		}
	}

	return 0;
}

#else

#define ll long long

using namespace std;

vector <pair<string, string>> names;
char input[50];

#define SZ 10000

struct satSolver {
    // SZ must be 2 times number of variables
    vector <int> graph[SZ], rgraph[SZ];
    int n, visited[SZ], component[SZ];

    satSolver (int n) : n(n) {}

    // [1..n], use -a for not a
    void add_formula (int a, int b){
        a = get_value(a);
        b = get_value(b);
        graph[a^1].push_back (b);
        graph[b^1].push_back (a);
    }

    int get_value(int v){
        return 2 * (abs (v) - 1) ^ (v < 0);
    }

    void solve (){
        for (int v = 0; v < 2 * n; v++)
            for (int u: graph[v])
                rgraph[u].push_back (v);
        stack <int> s;
        memset(visited, false, sizeof visited);
        for (int i = 0; i < 2 * n; i++) dfs1(i, s);
        memset(visited, false, sizeof visited);

        int c = 0;
        while (!s.empty()){
            int v = s.top();
            s.pop();
            dfs2 (v, c++);
        }
    }

    void dfs1 (int v, stack <int> &s){
        if (visited[v]) return;
        visited[v] = true;
        for (int u: graph[v])
            dfs1(u, s);
        s.push(v);
    }

    void dfs2 (int v, int c){
        if (visited[v]) return;
        visited[v] = true;
        component[v] = c;
        for (int u: rgraph[v]) dfs2 (u, c);
    }

    bool is_possible (){
        for (int i = 1; i <= n; i++)
            if (component[get_value(i)] == component[get_value(-i)]) return false;
        return true;
    }

    bool trueorfalse (int i){
        if (component[get_value(-i)] < component[get_value(i)]) return true;
        return false;
    }

};

string getfirst (int i){
    string s;
    s += names[i].first[0];
    s += names[i].first[1];
    s += names[i].first[2];
    return s;
}

string getsecond (int i){
    string s;
    s += names[i].first[0];
    s += names[i].first[1];
    s += names[i].second[0];
    return s;
}

int main(){
    int n;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++){
        scanf ("%s", input);
        names.push_back({input, ""});
        scanf ("%s", input);
        names.back().second = input;
    }

    satSolver sat (2000);

    for (int i = 1; i <= names.size(); i++){
        for (int j = i + 1; j <= names.size(); j++){

            if (getfirst(i-1) == getfirst(j-1)){
                sat.add_formula(-i, -i);
                sat.add_formula(-j, -j);
            }
            if (getsecond(i-1) == getsecond(j-1)){
                sat.add_formula(i, j);
            }
            if (getfirst(i-1) == getsecond(j-1)){
                sat.add_formula (-i, j);
            }
            if (getsecond(i-1) == getfirst(j-1)){
                sat.add_formula (i, -j);
            }
        }
    }

    sat.solve();
    if (!sat.is_possible()){
        printf ("NO\n");
        return 0;
    }
    printf ("YES\n");
    for (int i = 1; i <= n; i++){
        if (sat.trueorfalse(i))
            printf ("%s\n", getfirst(i-1).c_str());
        else
            printf ("%s\n", getsecond(i-1).c_str());

    }
    return 0;
}
#endif

