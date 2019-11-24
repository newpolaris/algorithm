#include <cstdio>
int t, n, c, p[4], a[3];
bool inside(int i) {
    int k0 = (a[0] - p[2*i + 0]);
    int k1 = (a[1] - p[2*i + 1]);
    return k0*k0 + k1*k1 <= a[2]*a[2];
}
int main() {
#ifdef _DEBUG
    freopen("1004.in", "r", stdin);
#endif
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %d", &p[0], &p[1], &p[2], &p[3]);
        scanf("%d", &n);
        c = 0;
        while (n--) {
            scanf("%d %d %d", &a[0], &a[1], &a[2]);
            if (inside(0) ^ inside(1)) c++;
        }
        printf("%d\n", c);
    }
    return 0;
}
