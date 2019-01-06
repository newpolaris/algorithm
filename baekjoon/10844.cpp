#include <cstdio>
#include <cstdint>
#include <algorithm>
int n, mod = 1'000'000'000;
int cache[101][10];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < 10; i++) cache[1][i] = 1;
    for (int l = 2; l <= n; l++) {
        cache[l][0] = cache[l-1][1];
        cache[l][9] = cache[l-1][8];
        for (int i = 1; i < 9; i++)
            cache[l][i] = (cache[l-1][i-1] + cache[l-1][i+1]) % mod;
    }
    int sum = 0;
    for (int i = 1; i <= 9; i++)
        sum = (sum + cache[n][i]) % mod;
    printf("%d\n", int(sum));
    return 0;
}
