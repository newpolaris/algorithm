#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
#if _DEBUG
	freopen("christmas.in", "r", stdin);
#endif

	int T, N, K;
	cin >> T;
	while (T--)
	{
		cin >> N >> K;
		vi in(N);
		for (auto& i : in)
			cin >> i;
		vi sum(N+1, 0);
		for (int i = 0; i < N; i++)
			sum[i+1] = (in[i] + sum[i]) % K;
		vector<int> L(K, 0);
		for (auto& i : sum) L[i]++;
		ll A = 0;
		for (ll l : L)
			if (l >= 2)
				A = (A + l*(l-1)/2) % 20091101;

		vector<vi> H(K);
		for (int i = 0; i < N+1; i++)
			H[sum[i]].push_back(i);
		vector<pii> G;
		for (auto& h : H)
			if (h.size() > 1)
				for (int i = 0 ; i+1 < h.size(); i++)
					G.push_back({h[i+1], h[i]});
		sort(begin(G), end(G));
		int last = -1, B = 0;
		for (auto& g : G)
			if (g.second >= last)
			{
				last = g.first;
				B++;
			}
		cout << A << " " << B << endl;
	}

	return 0;
}
