#include <cstdio>
#include <cstdint>
int main() {
    int64_t n;
    scanf("%lld", &n);
    int64_t cache[31] = { 0, };
    cache[0] = 1;
    cache[2] = 3;
    for (int i = 3; i <= n; i++) {
        cache[i] = 0;
        cache[i] += cache[i - 2] * 3;
        // 1+2*n+1 구조를 더한다
        for (int k = 4; k <= i; k += 2)
            if (i - k >= 0)
                cache[i] += cache[i - k] * 2;
    }
    printf("%lld\n", cache[n]);
    return 0;
}
