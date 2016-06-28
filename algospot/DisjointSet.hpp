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

