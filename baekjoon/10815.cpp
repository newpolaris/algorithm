#include <cstdio>
#include <algorithm>
int n, m, k, cards[500'001];
bool found(int a) {
    int l = 1, r = n;
    while (r - l >= 0) {
        int m = (r + l) / 2;
        if (cards[m] == a)
            return true;
        else if (cards[m] < a)
            l = m+1;
        else
            r = m-1;
    }
    return false;
}

int main() {
#ifdef _DEBUG
	freopen("10815.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &cards[i]);
    std::sort(&cards[1], &cards[n+1]);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &k);
        printf("%d%c", found(k), " \n"[i == m]);
    }
    return 0;
}
