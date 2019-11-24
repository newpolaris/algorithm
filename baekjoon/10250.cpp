#include <cstdio>
int t, n, r, c;
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &r, &c, &n);
        int col = (n - 1) / r + 1, row = (n - 1) % r + 1;
        printf("%d%02d\n", row, col);
    }
    return 0;
}
