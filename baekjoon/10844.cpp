#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <cstring>
int n, mod = 1'000'000'000;
int cache[101][10][1<<10];
int main() {
    scanf("%d", &n);
    memset(cache, 0, sizeof(cache));
    for (int i = 0; i < 10; i++) 
        cache[1][i][1<<i] = 1;
    for (int l = 2; l <= n; l++) {
        for (int k = 1; k < (1<<10); k++) {
            cache[l][0][k | (1 << 0)] += cache[l-1][1][k];
            cache[l][0][k | (1 << 0)] %= mod;
            cache[l][9][k | (1 << 9)] += cache[l-1][8][k];
            cache[l][9][k | (1 << 9)] %= mod;
        }
        for (int i = 1; i < 9; i++)
            for (int k = 1; k < (1<<10); k++) {
                cache[l][i][k | (1 << i)] += (cache[l-1][i-1][k] + cache[l-1][i+1][k]) % mod;
                cache[l][i][k | (1 << i)] %= mod;
            }
    }
    int sum = 0;
    int allset = 1024 - 1;
    for (int i = 1; i <= 9; i++)
        sum = (sum + cache[n][i][allset]) % mod;
    printf("%d\n", int(sum));
    return 0;
}
