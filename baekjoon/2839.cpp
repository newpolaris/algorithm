#include <cstdio>
#include <algorithm>
int cache[5001];
int k(int t) {
    if (t < 0) return -1;
    if (t == 0) return 0;
    if (cache[t]) return cache[t];
    int a = k(t - 3);
    int b = k(t - 5);
    if (a < 0 && b < 0) return -1;
    int s = 100'000;
    if (a >= 0) s = std::min(s, a);
    if (b >= 0) s = std::min(s, b);
    return cache[t] = s + 1;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
        k(i);
    printf("%d\n", k(n));
}
