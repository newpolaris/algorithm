#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("873b2.in", "r", stdin);
#endif
	int n;
	cin >> n;
	string s;
	cin >> s;
	std::vector<int> balance(n+1);
	balance[0] = 0;
	for (int i = 1; i <= n; i++)
		balance[i] = balance[i-1] + (s[i-1] == '0' ? 1 : -1);
	const int inf = int(1e7+1);
	std::vector<int> minIndex(2*n+1, inf);
	for (int i = 0; i <= n; i++)
		minIndex[n+balance[i]] = min(minIndex[n+balance[i]], i);
	int sol = 0;
	for (int i = 1; i <= n; i++)
		sol = max(sol, i - minIndex[n+balance[i]]);
	cout << sol << endl;
	return 0;
}
