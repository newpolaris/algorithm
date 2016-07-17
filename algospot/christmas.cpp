#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
		typedef vector<int> vi;
		vi in(N);
		for (auto& i : in)
			cin >> i;
		int r = 0;
		for (auto& i : in)
			i = r = (i + r) % K;
		vector<int> L(K, 0);
		for (auto& i : in)
			L[i]++;
		long long A = 0;
		for (long long l : L)
			if (l >= 2)
				A = (A + l*(l-1)/2) % 20091101;

		vector<vector<int>> H(K);
		H[0].push_back(0);
		for (int i = 0; i < in.size(); i++)
			H[in[i]].push_back(i+1);
		vector<pair<int,int>> G;
		for (auto& h : H)
			if (h.size() > 1)
				for (int i = 0 ; i+1 < h.size(); i++)
					G.push_back({h[i+1], h[i]});

		sort(begin(G), end(G));
		int last = -1, B = 0;
		for (auto& g : G)
		{
			if (g.second > last)
			{
				last = g.second;
				B++;
			}
		}
		cout << A << " " << B << endl;
	}

	return 0;
}
