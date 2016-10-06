#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std; 

int main() {
#ifdef _DEBUG
	freopen("710b.in", "r", stdin);
#endif

	int n;
	cin >> n;

	vector<int> x(n);
	for (auto& i : x)
		cin >> i;
	
	sort(x.begin(), x.end());
	int k = 0;
	if (n % 2)
		k = n/2;
	else
		k = n/2 - 1;

	cout << x[k] << endl;

	return 0;
}
