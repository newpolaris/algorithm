#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <regex>
#include <cassert>
#include <map>
#include <queue>
#include <set>
#include <numeric>

#define ALL(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define x first
#define y second

using namespace std;

// editorwar 의 BipartiteUnionFind 를 활용한다.
class DisjointSet
{
public:
	vector<int> parent, rank, enemy;
	DisjointSet(int n) {
		parent.resize(n);
		iota(ALL(parent), 0);
		rank.assign(n, 0);
		enemy.assign(n, -1);
	}
	int find(int a) {
		if (a != parent[a]) 
			parent[a] = find(parent[a]);
		return parent[a];
	}
	int merge(int a, int b) {
		if (a == -1 || b == -1)
			return max(a, b);
		auto pa = find(a), pb = find(b);
		if (pa == pb) return pa;
		if (rank[pa] > rank[pb]) 
			swap(pa, pb);
		/*
		 * 이제 rank(b)가 항상 rank(a) 이상이므로 a를 b의 자식으로 넣는다.
		 * 긴 곳에 넣어야 높이가 변화가 없다
		 */
		parent[pa] = pb;
		if (rank[pa] == rank[pb])
			++rank[pb];
		return pb;
	}
	bool dis(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		auto ea = enemy[a], eb = enemy[b];
		a = merge(a, eb);
		ea = merge(b, ea);
		enemy[a] = ea;
		enemy[ea] = a;
		return true;
	}
	bool ack(int a, int b) {
		a = find(a), b = find(b);
		auto ea = enemy[a], eb = enemy[b];
		if (a == eb) return false;
		a = merge(a, b);
		ea = merge(ea, eb);
		enemy[a] = ea;
		if (ea != -1)
			enemy[ea] = a;
		return true;
	}
	// 확인만 한다, 같은 집합 0, 다르면 1, 모르겠으면 2
	int check(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return 0;
		auto ea = enemy[a], eb = enemy[b];
		if (a == eb) return 1;
		return 2;
	}
};

int main() {
#ifdef _DEBUG
	freopen("766d.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);

	int n, m, q, t;
	string a, b;
	cin >> n >> m >> q;
	vector<string> words(n);
	for (auto& w : words)
		cin >> w;
	// sort 와 lower_bound 를 쓰면 map 안써도 어느정도 속도는 확보 가능
	sort(ALL(words));
	auto getIdx = [&](const string& s) {
		return distance(words.begin(), lower_bound(ALL(words), s));
	};

	DisjointSet set(n);

	REP(i, 0, m) {
		cin >> t >> a >> b;
		int ai = getIdx(a), bi = getIdx(b);
		auto check = [&set](int t, int ai, int bi) {
			// ack, dis 자체가 확인을 수행함
			if (t == 1) return set.ack(ai, bi);
			else return set.dis(ai, bi);
		};
		cout << (check(t, ai, bi) ? "YES" : "NO") << endl;
	}
	REP(i, 0, q) {
		cin >> a >> b;
		int ai = getIdx(a), bi = getIdx(b);
		cout << (set.check(ai, bi) + 1) << endl;
	}

	return 0;
}
