#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("919b0.in", "r", stdin);
#endif
	int i, k;
	cin >> k;
	int cnt = 0;
	for (i = 0; i < 1e9; i++) 
	{
		int t = i;
		int w = 0;
		while (t > 0) {
			w += t % 10;
			t /= 10;
		}
		if (w == 10) cnt++;
		if (cnt == k)
			break;
	}
	cout << i << endl;
	return 0;
}
