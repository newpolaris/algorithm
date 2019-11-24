#include <cstdio>
#include <numeric>
#include <queue>

int t, n, a;
int c[501][501];
int merge(int a, int b) {
    int& r = c[a][b];
    if (r > 0) return r;
    r = 10'000;
    for (int i = a; i < b; i++)
        r = std::min(r, merge(a, i) + merge(i+1, b));
    return r;
}

int main() {
#ifdef _DEBUG
    freopen("11066.in", "r", stdin);
#endif
    scanf("%d", &t);
    while (t--) {
        memset(c, -1, sizeof(c));
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &c[i][i]);
        printf("%d\n", merge(0, n-1));
    }
    return 0;
}
