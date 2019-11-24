#include <cstdio>
#include <cmath>
#include <algorithm>
int n, cache[100'001];
int main() {
    scanf("%d", &n);
    for (int k = 1; k <= n; k++) {
        cache[k] = 100'000;
        for (int i = 1; i*i <= k; i++) {
            int remain = k - i*i;
            cache[k] = std::min(cache[remain] + 1, cache[k]);
        }
    }
    printf("%d\n", cache[n]);
    return 0;
}
