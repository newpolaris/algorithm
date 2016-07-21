#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

int main()
{
#ifdef _DEBUG
	freopen("ites.in","r",stdin);
#endif

	int C, K, N;
	cin >> C;
	while (C--)
	{
		cin >> K >> N;

		ll A = 1983, sum = 0, count = 1, num = 0, in = 1983;
		queue<ll> q;
		while (count <= N)
		{
			while (sum < K && count <= N)
			{
				q.push(in);
				sum += in;
				A = (A * 214013 + 2531011) % (ll(1) << 32);
				in = A % 10000 + 1;
				count++;
			}
			while (sum >= K)
			{
				if (sum == K)
					num++;
				ll in = q.front();
				sum -= in;
				q.pop();
			}
		}
		cout << num << endl;
	}

	return 0;
}

