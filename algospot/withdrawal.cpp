#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("withdrawal.in", "r", stdin);
#endif
	int T;
	cin >> T;
	while (T--)
	{
		int N, K;
		cin >> N >> K;
		double lo = 0.0, hi = 1.0;
		vector<int> R(N), C(R);
		for (int i = 0; i < N; i++)
			cin >> R[i] >> C[i];
		auto p = [&](double mid)
		{
			vector<double> S(N);
			for (int i = 0; i < N; i++)
				S[i] = mid * C[i] - R[i];
			sort(S.begin(), S.end());
			return accumulate(S.rbegin(), S.rbegin() + K, 0.0) >= 0.0;
		};

		while (hi - lo > 0.000000001)
		{
			auto mid = (hi + lo)/2;
			if (p(mid))
				hi = mid;
			else
				lo = mid;
		}
		cout << fixed << setprecision(8);
		cout << lo << endl;
	}

	return 0;
}
