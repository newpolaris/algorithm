#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>

using namespace std;
int main() {
	ios::sync_with_stdio(0);
	vector<int> c(int(1e6)+2, int(1e10));
	c[1] = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) { 
		c[i+1] = min(c[i+1], c[i]+1);
		if (i*2 < c.size()) c[i*2] = min(c[i*2], c[i]+1);
		if (i*3 < c.size()) c[i*3] = min(c[i*3], c[i]+1);
	}
	cout << c[n] << endl;
	return 0;
}
