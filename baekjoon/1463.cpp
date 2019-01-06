#include <cstdio>
int min(int a, int b) {
    return a <= b ? a : b;
}
int main() {
    int n, c[1'000'000];
	c[1] = 0, c[2] = 1, c[3] = 1;
    scanf("%d", &n);
	for (int i = 4; i <= n; i++) { 
        int t = c[i-1];
        if (i % 2 == 0) t = min(c[i/2], t);
        if (i % 3 == 0) t = min(c[i/3], t);
        c[i] = t + 1;
	}
    printf("%d\n", c[n]);
	return 0;
}
