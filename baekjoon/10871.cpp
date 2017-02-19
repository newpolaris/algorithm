#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
#ifdef _DEBUG
#endif
	ios::sync_with_stdio(0);
	int n, x, c;
	scanf("%d%d", &n, &x);
	while (n--) {
		scanf("%d", &c);
		if (x > c) printf("%d ",c);
	}
	printf("\n");

	return 0;
}
