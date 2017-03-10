#include <stdio.h>
#include <math.h>

int max(int a, int b) {
	return a > b ? a : b;
}
int main() {
#ifdef _DEBUG
	freopen("9465.in", "r", stdin);
#endif
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int sc[n][2], c[n+1][2];
		for (int j = 0; j < 2; j++)
			for (int i = 0; i < n; i++)
				scanf("%d", &sc[i][j]);

		c[0][0] = c[0][1] = 0;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				c[i][j] = max(sc[i][j]+c[i][(j+1)%2], sc[i-1][j]);
			}
		}
		printf("%d\n", max(sc[n-1][0], sc[n-1][1]));
	}
	return 0;
}
