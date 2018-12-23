#include <iostream>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("917b0.in", "r", stdin);
#endif
	int x, h, m;
	cin >> x >> h >> m;
	int min = h*60 + m;
	int cnt = 0;

	auto lucky = [](int k) {
		return ((k / 10) == 7) || (k%10 == 7);
	};

	auto check = [&](void) {
		if (min < 0)
			min += 24*60;
		int h = min / 60;
		int m = min % 60;
		return lucky(h) || lucky(m);
	};

	while (!check())
	{
		min -= x;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}
