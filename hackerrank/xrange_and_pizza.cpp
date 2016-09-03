#include <iostream>
#include <vector>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("xrange_and_pizza.in", "r", stdin);
#endif
	
	int n, m, t, k;

	cin >> n >> m;

	bool bFlip = false;
	int zeroPos = 0;

	while (m--)
	{
		cin >> t >> k;
		if (t == 1) {
			zeroPos = (zeroPos+k) % n;
		} else {
			bFlip = !bFlip;
			zeroPos = (k - zeroPos + n) % n;
		}
	}
	t = bFlip ? 2 : 1;
	if (t == 1) {
		k = (n - zeroPos) % n;
	} else {
		k = zeroPos;
	}
	cout << t << " " << k << endl;

	return 0;
}

