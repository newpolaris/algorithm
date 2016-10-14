#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 상호 배타적 집합 자료 구조를 구현한다.
struct DisjointSet {
	// n개의 원소로 구성된 집합 자료 구조를 만든다.
	DisjointSet(int n);
	// here가 포함된 집합의 대표를 반환한다.
	int find(int here);
	// a가 포함된 집합과 b가 포함된 집합을 합친다.
	bool merge(int a, int b);

	vector<int> P, Rank;
};

DisjointSet::DisjointSet(int n)
{
	P.resize(n);
	for (int i = 0; i < n; i++)
		P[i] = i;
	Rank = vector<int>(n, 0);
}

int DisjointSet::find(int here)
{
	if (P[here] != here)
		P[here] = find(P[here]);
	return P[here];
}

bool DisjointSet::merge(int a, int b)
{
	int ra = find(a), rb = find(b);
	if (ra == rb) return false;
	if (Rank[ra] > Rank[rb])
		P[rb] = ra;
	else
		P[ra] = rb;
	if (Rank[ra] == Rank[rb]) 
		Rank[rb] = Rank[ra] + 1;
	return true;
}

typedef long long ll;

int main()
{
#ifdef _DEBUG
	freopen("722c.in", "r", stdin);
#endif

	int n;
	cin >> n;
	vector<ll> rsum(n);
	for (auto & r : rsum)
		cin >> r;
	vector<int> elim(n);
	for (auto & e : elim) {
		cin >> e;
		e--;	
	}
	vector<bool> used(n, false);

	DisjointSet set(n);
	ll maxV = 0;
	vector<ll> st;
	st.push_back(maxV);

	for (int i = n - 1; i > 0; i--) {
		int elm = elim[i];
		used[elm] = true;
		maxV = max(rsum[elm], maxV);

		auto update = [&](int e, int elm) {
			int ra = set.find(e);
			int rb = set.find(elm);
			set.merge(e, elm);
			int root = set.find(elm);
			rsum[root] = rsum[ra] + rsum[rb];
			maxV = max(rsum[root], maxV);
		};

		// left & right
		if (elm > 0 && used[elm-1]) {
			update(elm-1, elm);
		}
		// right
		if (elm < n - 1 && used[elm+1]) {
			update(elm+1, elm);
		}
		st.push_back(maxV);
	}
	for (auto rit = st.rbegin(); rit != st.rend(); ++rit) {
		cout << *rit << endl;
	}

	return 0;
}

