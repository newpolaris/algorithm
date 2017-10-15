#include <cstdio>
#include <cmath>
#include <algorithm>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = -n+1; i < n; i++) {
		for (int j = 0; j < std::min(i,-i)+n-1; j++) printf(" ");
		for (int j = 0; j < 2*std::abs(-i)+1; j++) printf("*");
		printf("\n");
	}
	return 0;
}
