#include <cstdio>
#include <cstdint>
int n, k, lines[10'001];
int64_t count(int64_t cut) {
    int64_t cnt = 0;
    for (int i = 0; i < k; i++)
        cnt += lines[i] / cut;
    return cnt;
}

int main() {
#ifdef _DEBUG
    freopen("1654.in", "r", stdin);
#endif
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++) scanf("%d", &lines[i]);
#if 0
    int64_t lo = 0, hi = (1u << 31);
    while (lo + 1 < hi) {
        int64_t mid = (hi + lo) / 2;
        if (count(mid) >= n)
            lo = mid;
        else
            hi = mid;
    }
#else
    int64_t lo = 1, hi = (1u << 31);
    while (lo < hi) {
        int64_t mid = lo + (hi - lo)/2;
        if (count(mid) >= n)
            lo = mid+1;
        else 
            hi = mid;
    }
    if (count(lo) < n)
        lo = lo - 1;
#endif
    printf("%d\n", int(lo));
    return 0;
}
