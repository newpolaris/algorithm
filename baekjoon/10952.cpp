#include <cstdio>
int main() {
	while (true) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a+b == 0) break;
		printf("%d\n", a+b);
	}
	return 0;
}
