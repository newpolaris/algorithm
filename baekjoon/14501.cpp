#include <cstdio>
#include <cstring>
#include <algorithm>
int n, cache[100], t[100], p[100];
void dp(int d) {
    if (d + t[d] <= n) {
        cache[d] = cache[d + t[d]] + p[d];
    }
    cache[d] = std::max(cache[d], cache[d+1]);
}

int main() {
#ifdef _DEBUG
    freopen("14501.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &t[i], &p[i]);
    memset(cache, 0, sizeof(cache));
    for (int i = n - 1; i >= 0; i--)
        dp(i);
    printf("%d\n", cache[0]);
    return 0;
}
