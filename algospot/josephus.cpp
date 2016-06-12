#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("josephus.in", "r", stdin);
#endif
	int C, N, K;
	cin >> C;
	while (C--) {
		cin >> N >> K;
		deque<int> Q;
		for (int i = 1; i <= N; i++) Q.push_back(i);
		while (Q.size() > 2)
		{
			Q.pop_front();
			for (int i = 0; i < K - 1; i++)
			{
				int num = Q.front();
				Q.pop_front();
				Q.push_back(num);
			}
		}
		sort(begin(Q), end(Q));
		cout << Q[0] << " " << Q[1] << endl;
	}
	return 0;
}

