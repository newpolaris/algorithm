#include <cstdio>
#include <algorithm>
int n, k;
int cache[100][100];
int comb(int n, int k) {
    if (n <= 0) return 0;
    if (k == 0) return 1;
    if (k == 1) return n;
    if (cache[n][k] > 0) return cache[n][k];
    return cache[n][k] = comb(n-1, k-1) + comb(n-1,k);
}
int main() {
    scanf("%d %d", &n, &k);
    printf("%d\n", comb(n, std::min(n - k, k)));
    return 0;
}
