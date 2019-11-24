#include <cstdio>
#include <cstdint>
#include <algorithm>

int n, k;
int main() {
    scanf("%d %d", &n, &k);
    int64_t lo = 0, hi = 1'000'000'000 + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        int64_t cnt = 0;
        for (int i = 1; i <= n; i++)
            cnt += std::min(mid/i, n);
        if (cnt < k)
            lo = mid;
        else
            hi = mid;
    }
    printf("%lld\n", hi);
    return 0;
}
