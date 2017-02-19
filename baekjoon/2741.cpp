#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;
int main() {
	int n;
	ios::sync_with_stdio(0);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		printf("%d\n", i);
	}
}
