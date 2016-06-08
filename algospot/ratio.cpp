#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
#ifdef _DEBUG
	freopen("ratio.in", "r", stdin);
#endif
	int T;
	cin >> T;
	while (T--)
	{
		ll N, M, Z, low, high, mid;
		cin >> N >> M;
		Z = (M * 100)/N;
		auto p = [&](ll mid) { return (M+mid)*100/(N+mid) > Z; };
		low = 1;
		high = 2000000000;
		while (low < high)
		{
			mid = (low + high)/2;
			if (p(mid) == true) high = mid;
			else low = mid + 1;
		}
		if (p(low) == false) low = -1;
		cout << low << endl;
	}

	return 0;
}
