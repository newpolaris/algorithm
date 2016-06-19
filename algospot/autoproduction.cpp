#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("autoproduction.in","r",stdin);
#endif

	int T, N, R, C;

	cin >> T;
	while (T--)
	{
		cin >> N;
		int PRO = 1001;
		for (int i = 0; i < N; i++)
		{
			cin >> R >> C;
			int sum = 0, k;
			for (int i = 0; i < C; i++) {
				cin >> k;
				sum += k;
			}
			PRO = min(PRO, sum / R);
		}
		cout << PRO << endl;
	}
	return 0;
}

