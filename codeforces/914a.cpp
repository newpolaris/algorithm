#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
#ifdef _DEBUG
#endif
	int n, k;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	int ans = -1e6;
	vector<bool> l(1e6+1, false);
	for (int i = 1; i < sqrt(1e6+1); i++)
		l[i*i] = true;
	l[0] = true;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
			ans = max(ans, a[i]);
		else
		{
			if (!l[a[i]])
				ans = max(ans, a[i]);
		}
	}
	cout << ans << endl;
	return 0;
}
