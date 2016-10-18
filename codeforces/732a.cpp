#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std; 

int main() {
#ifdef _DEBUG
	freopen("732a.in", "r", stdin);
#endif

	int k, r;
	cin >> k >> r;
	k %= 10;
	int ans = 1, x = k;
	while (x != r && x > 0)
	{
		ans++;
		x += k;
		x %= 10;

	}
	cout << ans << endl;

	return 0;
}
