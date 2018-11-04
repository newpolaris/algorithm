#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct BipartiteUnionFind {
	vector<int> parent, rank, enemy, size;
	BipartiteUnionFind(int n) 
		: parent(n), rank(n, 0), enemy(n, -1), size(n, 1) 
	{
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	int merge(int a, int b) {
		// a나 b가 공집합인 경우 나머지 하나를 반환한다.
		if (a == -1 || b == -1) 
			return max(a, b);
		a = find(a), b = find(b);
		// 이미 둘이 같은 트리에 속한 경우
		if (a == b) return a;

		if (rank[a] > rank[b])
			swap(a, b);
		// 이제 항상 rank[b]가 더 크므로 a를 b의 자식으로 넣는다. 
		if (rank[a] == rank[b]) rank[b]++;
		parent[a] = b;
		size[b] += size[a];
		return b;
	}
	// u와v가 서로 적대하는 집합에 속한다.
	bool dis(int u, int v) {
		// 우선 루트를 찾는다.
		u = find(u), v = find(v);
		// 같은 집합에 속해 있으면 모순!
		if (u == v) return false;
		// 적의 적은 나의 동지
		int a = merge(u, enemy[v]), b = merge(v, enemy[u]);
		enemy[a] = b; enemy[b] = a;
		return true;
	}
	// u와 v가 같은 집합에 속한다.
	bool ack(int u, int v) {
		// 우선 루트를 찾는다.
		u = find(u), v = find(v);
		// 두 집합이 서로 적대 관계라면 모순!
		if (enemy[u] == v) return false;
		//동지의 적은 나의 적
		int a = merge(u, v), b = merge(enemy[u], enemy[v]);
		enemy[a] = b;
		// u, v 모두 아직 적대 집합이 설정되지 않았다면 b 가 -1 일 수 있다.
		if (b != -1) enemy[b] = a;
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

int main()
{
#ifdef _DEBUG
	freopen("../algospot/editorwars.in", "r", stdin);
#endif
	int C, N, M, a, b, e;
	string w;
	cin >> C;
	while (C--) {
		cin >> N >> M;
		bool bPass = true;
		BipartiteUnionFind A(N);
		for (int i = 1; i <= M; i++) {
			cin >> w >> a >> b;
			if (!bPass) continue;
			bPass = (w == "ACK") ? A.ack(a, b) : A.dis(a, b);
			if (!bPass) {
				cout << "CONTRADICTION AT " << i << endl;
			}
		}
		if (!bPass) continue;

		int ret = 0;
		for (int node = 0; node < N; ++node) {
			if (A.find(node) == node) {
				int enemy = A.enemy[node];
				// 같은 모임 쌍을 두 번 세지 않기 위해,
				// enemy < node인 경우 만 센다.
				// enemy == -1 인경우도 정확히 한번 씩 세게 된다.
				if (enemy > node) continue;
				int mySize = A.size[node];
				int enemySize = (enemy == -1 ? 0 : A.size[enemy]);
				// 두 집합 중 큰 집합을 더한다.
				ret += max(mySize, enemySize);
			}
		}

		cout << "MAX PARTY SIZE IS " << ret << endl;
	}

	return 0;
}
