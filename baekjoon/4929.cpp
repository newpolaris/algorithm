#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int s = 20'002, d = 10'000;
int n, k;
int main() {
#ifdef _DEBUG
    freopen("4929.in", "r", stdin);
#endif
    while (true) {
        int a[s];
        memset(a, 0, sizeof(a));
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &k);
            a[k+d] |= 1;
        }
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &k);
            a[k+d] |= 2;
        }
        int p = 0, q = 0, c = 0;
        for (int i = 0; i < s; i++) {
            if (a[i] & 1) p += (i - d);
            if (a[i] & 2) q += (i - d);
            if ((a[i] & 3) == 3) {
                c += std::max(p, q);
                p = 0, q = 0;
            }
        }
        c += std::max(p, q);
        printf("%d\n", c);
    }
    return 0;
}
