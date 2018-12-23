#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("914b1.in", "r", stdin);
#endif
	int n, k;
	cin >> n;
	vector<int> a(1e5+1);
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		a[k]++;
	}
	for (int i = a.size() - 1; i >= 0; i--)
	{
		if (a[i] > 0 && ((a[i] % 2) == 1))
		{
			cout << "Conan" << endl;
			return 0;
		}
	}
	cout << "Agasa" << endl;
	return 0;
}
