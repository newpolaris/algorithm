#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	long long c[100];
	c[0] = c[1] = c[2] = 1;
	c[3] = c[4] = 2;
	for (int i = 0; i+5 < 100; i++)
		c[i + 5] = c[i] + c[i+4];
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << c[n-1] << endl;
	}
	return 0;
}
