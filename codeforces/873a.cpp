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
	freopen("873a0.in", "r", stdin);
#endif
	int n, k, x;
	ios_base::sync_with_stdio(false);
	cin >> n >> k >> x; 
	std::vector<int> chore(n);
	for (auto& it : chore)
		cin >> it;
	int sum = 0;
	for (int i = 0; i < (n-k); i++)
		sum += chore[i];
	sum += k * x;
	cout << sum << endl;
}
