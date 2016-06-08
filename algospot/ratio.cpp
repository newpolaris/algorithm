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
		ll N, M, need;
		cin >> N >> M;
		auto rate = (double)M/N;
		rate += 0.01;
		rate *= 100.0;
		ll r = (ll)rate;
		if (r >= 100)
			need = -1;
		else {
			auto fNeed = (double)(r * N - 100 * M) / (100.0 - r);
			need = (ll)ceil(fNeed);
		}
		cout << need << endl;
	}

	return 0;
}
