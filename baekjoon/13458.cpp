#include <cstdio>
#include <cstdint>
#include <algorithm>
int n, a[1'000'000], b, c;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d %d", &b, &c);
    int64_t cnt = 0;
    for (int i = 0; i < n; i++) {
        a[i] -= std::min(b, a[i]);
        cnt++;
        cnt += (a[i] + c - 1) / c;
    }
    printf("%lld\n", cnt);
    return 0;
}
