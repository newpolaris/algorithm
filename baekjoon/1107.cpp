#include <cstdio>
#include <algorithm>
bool table[10] = { false, };
int n, m, d;
int calc(int p) {
    int k = p;
    int c = 0;
    do {
        if (table[k % 10])
            return 1'000'000;
        k /= 10;
        c++;
    } while (k);
    return std::abs(n - p) + c;
}

int main() {
#ifdef _DEBUG
    freopen("1107.in", "r", stdin);
#endif
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &d);
        table[d] = true;
    }
    int q = std::abs(n - 100);
    for (int i = 0; i <= 1'000'000; i++)
        q = std::min(q, calc(i));
    printf("%d\n", q);
}
