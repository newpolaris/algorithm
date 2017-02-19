#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;
int main() {
	int n;
	ios::sync_with_stdio(0);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++)
			printf(" ");
		for (int j = n-i; j > 0; j--)
			printf("*");
		printf("\n");
	}
	return 0;
}
