#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int L[101], R[101], V[101];

void travel(vector<int>& list, int node)
{
	if (node == 0) return;
	travel(list, L[node]);
	list.push_back(V[node]);
	travel(list, R[node]);
}

int main() {
#ifdef _DEBUG
	freopen("bst.in", "r", stdin);
#endif
	int T, N;	

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> L[i] >> R[i] >> V[i];
		vector<int> P(N+1, 0);
		for (int i = 1; i <= N; i++)
			P[L[i]] = P[R[i]] = i;
		int root = 1;
		while (P[root] != 0) root++;
		vector<int> list;
		travel(list, root);
		if (adjacent_find(list.begin(), list.end(),
					greater_equal<int>()) == list.end())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
