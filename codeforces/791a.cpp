#include <iostream>
#include <map>
#include <algorithm>

#define x first
#define y second

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("791a.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a, b;
	cin >> a >> b;
	int i = 0;
	while (a <= b) {
		a *= 3;
		b *= 2;
		i++;
	}
	cout << i << endl;
	return 0;
}
