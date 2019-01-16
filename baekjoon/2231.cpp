#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int k = i;
        int s = k;
        while (k) {
            s += k % 10;
            k /= 10;
        }
        if (s == n) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("%d\n", 0);
    return 0;
}
