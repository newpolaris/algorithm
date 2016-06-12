#include <iostream>
#include <vector>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("diamondpath.in", "r", stdin);
#endif

	int C, N;
	cin >> C;
	while (C--) {
		cin >> N;
		vector<int> S(N+1);
		for (int r = 0; r < 2*N-1; r++) {
			vector<int> I(N), T(N+1);
			int k = r >= N ? 2*N - 1 - r : r + 1;
			int shift = r >= N ? N - k : 0;
			for (int c = 0; c < k; c++)
				cin >> I[c+shift];
			for (int c = shift; c < k+shift; c++)
				T[c+1] = I[c] + max(S[c], S[c+1]);
			S = T;
		}
		cout << S[N] << endl;
	}
	return 0;
}
