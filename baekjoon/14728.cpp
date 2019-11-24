#include <cstdio>
#include <algorithm>
int n, t, cache[10'001];
int main() {
#ifdef _DEBUG
    freopen("14728.in", "r", stdin);
#endif
    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; i++) {
        int k, s; scanf("%d %d", &k, &s);
        for (int j = t; j >= k; j--)
            cache[j] = std::max(cache[j], cache[j - k] + s);
    }
    printf("%d\n", cache[t]);
    return 0;
}
