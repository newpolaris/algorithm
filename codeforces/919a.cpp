#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("919a0.in", "r", stdin);
#endif
	int n, m, a, b;
	cin >> n >> m;
	double k = 10000.0;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		k = min(k, (double)m * a / b);
	}
	cout << std::fixed << std::setprecision(7) << k << endl;
	return 0;
}
