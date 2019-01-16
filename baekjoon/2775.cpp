#include <cstdio>
int t, k, n;
int p[15][15];
int main() {
    scanf("%d", &t);
    for (int i = 0; i < 15; i++)
        p[0][i] = i;
    for (int i = 1; i < 15; i++)
    for (int k = 1; k < 15; k++)
        p[i][k] = p[i][k-1] + p[i-1][k];
    while (t--) {
        scanf("%d %d", &k, &n);
        printf("%d\n", p[k][n]);
    }
    return 0;
}
