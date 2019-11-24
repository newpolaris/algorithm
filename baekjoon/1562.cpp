#include <cstdio>
#include <cstdint>
#include <algorithm>
int n, mod = 1'000'000'000;
int64_t cache[101][10];
int64_t count(int l, int i) {
    if (i < 0 || i > 9) return 0;
    return cache[l][i];
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < 10; i++) cache[1][i] = 1;
    for (int l = 2; l <= n; l++) 
        for (int i = 0; i < 10; i++)
            cache[l][i] = (count(l - 1, i - 1) + count(l - 1, i + 1)) % mod;
    int64_t sum = 0;
    for (int i = 1; i <= 9; i++)
        sum = (sum + cache[n][i]) % mod;
    printf("%d\n", int(sum));
    return 0;
}
