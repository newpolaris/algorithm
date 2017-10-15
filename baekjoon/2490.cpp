#include <cstdio>
int main() {
	for (int k = 0; k < 3; k++) {
		int a, b = 0;
		for (int i = 0; i < 4; i++) {
			scanf("%d", &a);
			if (a == 0) b++;
		}
		if (b == 0) b = 5;
		printf("%c\n", ('A'+b-1));
	}
	return 0;
}
