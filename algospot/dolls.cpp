#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

typedef long long ll;

int main()
{
#if _DEBUG
	freopen("dolls.in", "r", stdin);
#endif 

	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		vector<int> L(N), R(N);
		for (auto& l : L)
			cin >> l;
		int mid, low = 0, high = *max_element(begin(L), end(L));
		auto p = [&](int mid)
		{
			ll sum = 0;
			for (int i = 0; i < N; i++)
				sum += min(L[i], mid);
			return sum <= M;
		};
		while (low < high) {
			mid = low+(high-low+1)/2;
			if (p(mid)) low = mid;
			else high = mid - 1;
		}
		int r = M;
		for (int i = 0; i < N; i++)
		{
			int used = min(L[i], low);
			r -= used;
			R[i] = L[i] - used;
		}

		for (int i = 0; i < N; i++)
			if (R[i] > 0 and r) {
				r--;
				R[i]--;
			}

		for (int i = 0; i < N; i++) 
			cout << (L[i] - R[i]) << " ";
		cout << endl;
	}

	return 0;
}

