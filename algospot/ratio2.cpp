/*
 * int T = (int)((double) M / N * 100) + 1; // 기존 코드 (오답)
 * int T = (int)((double)(M * 100) / N) + 1; // 수정된 코드 (정답)
 */
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
		auto rate = (double)(M*100)/N + 1;
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
