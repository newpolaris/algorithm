#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>

using namespace std;
int main() {
	ios::sync_with_stdio(0);
	vector<int> c(15, 0);
	c[0] = 1;
	for (int i = 1; i <= 14; i++) {
		c[i] += c[i-1];
		if (i >= 2) c[i] += c[i-2];
		if (i >= 3) c[i] += c[i-3];
	}
	int C;
	scanf("%d", &C);
	while (C--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", c[n]);
	}
}
