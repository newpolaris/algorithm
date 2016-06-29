#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("darpa.in", "r", stdin);
#endif

	int C, N, M;
	cin >> C;
	while (C--)
	{
		cin >> N >> M;
		vector<float> L(M);
		for (auto &l : L)
			cin >> l;
		auto p = [&](float m) {
			int num = 1, Last = 0;
			for (int i = 1; i < L.size(); i++)
			{
				if (L[i] - L[Last] >= m)
				{
					Last = i;
					num++;
				}
			}
			return num >= N;
		};
		float lo = 0.f, hi = 240.0f;
		while (hi-lo > 0.0001f)
		{
			float mid = lo + (hi-lo)/2.0;
			if (p(mid))
				lo = mid;
			else
				hi = mid;
		}
		cout << fixed << setprecision(2);
		cout << lo << endl;
	}

	return 0;
}
