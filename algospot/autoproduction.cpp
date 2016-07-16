#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int need[10];
int bagNum[10];
int bag[10][10];

int main()
{
#ifdef _DEBUG
	freopen("autoproduction.in","r",stdin);
#endif

	int T, N, R;

	cin >> T;
	while (T--)
	{
		cin >> N;

		for (int n = 0; n < N; n++)
		{
			cin >> need[n] >> bagNum[n];
			for (int i = 0; i < bagNum[n]; i++)
				cin >> bag[n][i];
			sort(bag[n], bag[n]+bagNum[n], greater<int>());
		}

		auto fit = [&](int m) {
			int boxLimit = 10;
			for (int i = 0; i < N; i++)
			{
				int sum = 0;
				int require = m*need[i];
				for (int t = 0; t < bagNum[i]; t++) {
					if (require <= sum) 
						break; 
					sum += bag[i][t];
					boxLimit--;
					if (boxLimit < 0) 
						return false;
				}
				if (require > sum) 
					return false;
			}
			return true;
		};
		int lo = 0, hi = 10000;
		while (lo < hi)
		{
			int mid = lo + (hi - lo + 1) / 2;
			if (!fit(mid))
				hi = mid - 1;
			else
				lo = mid;
		}
		cout << lo << endl;
	}
	return 0;
}

