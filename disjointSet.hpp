#include <vector>

using namespace std;

// 상호 배타적 집합 자료 구조를 구현한다.
// O(a(n)) : find, merge
struct DisjointSet {
	// n개의 원소로 구성된 집합 자료 구조를 만든다.
	DisjointSet(int n);
	// here가 포함된 집합의 대표를 반환한다.
	int find(int here);
	// a가 포함된 집합과 b가 포함된 집합을 합친다.
	bool merge(int a, int b);

	vector<int> parent, rank;
};

DisjointSet::DisjointSet(int n)
{
	parent.resize(n);
	for (int i = 0; i < n; i++)
		parent[i] = i;
	rank = vector<int>(n, 0);
}

// here 가 속한 트리의 루트의 번호를 반환한다.
int DisjointSet::find(int here)
{
	// 모든 경로의 child 에 대해 경로 압축. 
	if (parent[here] != here)
		parent[here] = find(parent[here]);
	return parent[here];
}

// a가 속한 트리와 v가 속한 트리를 합친다.
bool DisjointSet::merge(int a, int b)
{
	int a = find(a), b = find(b);
	if (a == b) return false;
	if (rank[a] > rank[b]) 
		swap(a, b);
	// 이제 rank(b)가 항상 rank(a) 이상이므로 a를 b의 자식으로 넣는다.
	parent[a] = b;
	if (rank[a] == rank[b]) 
		++rank[b];

	return true;
}

