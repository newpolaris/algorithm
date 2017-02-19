#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;
int main() {
	int n;
	ios::sync_with_stdio(0);
	scanf("%d", &n);
	for (int i = n; i > 0; i--) {
		printf("%d\n", i);
	}
}
