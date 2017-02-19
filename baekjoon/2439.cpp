#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;
int main() {
	ios::sync_with_stdio(0);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = n-i; j > 0; j--)
			printf("*");
		printf("\n");
	}
	return 0;
}
