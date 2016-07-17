#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
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
		vi L(K, 0);
		for (auto& i : sum) L[i]++;
		ll A = 0;
		for (ll l : L)
			if (l >= 2)
				A = (A + l*(l-1)/2) % 20091101;

		// greedy algorihtm : meeting problem
		// 가장 먼저 마치는 구간을 탐욕적으로 택한다
		vi H(K, -1);
		int last = 0, B = 0;
		for (int i = 0; i < N+1; i++) {
			auto r = sum[i];
			if (H[r] >= last) {
				B++;
				last = i;
			}
			H[r] = i;
		}
		cout << A << " " << B << endl;
	}

	return 0;
}
