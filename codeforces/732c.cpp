#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std; 

int main() {
#ifdef _DEBUG
	freopen("732c.in", "r", stdin);
#endif

	typedef long long ll;
	ll a, b, c;
	cin >> a >> b >> c;
	auto maxK = max(max(a, b), c);
	ll diff = 0;
	if (maxK > a) diff += (maxK - a - 1);
	if (maxK > b) diff += (maxK - b - 1);
	if (maxK > c) diff += (maxK - c - 1);
	cout << diff << endl;

	return 0;
}
