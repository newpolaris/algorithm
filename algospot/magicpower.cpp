#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("magicpower.in", "r", stdin);
#endif

	int T, N, M;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		vector<int> L(N);
		for (auto& l : L)
			cin >> l;
		vector<int> k;
		for (int i = 0; i < N; i++)
			for (int a = 1; a <= L[i]; a++)
				k.push_back(a);
		sort(k.begin(), k.end(), greater<int>());
		int l = min((int)k.size(), M);
		int sum = accumulate(k.begin(), k.begin()+l, 0);
		cout << sum << endl;
	}
}

