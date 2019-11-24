#include <cstdio>
int n, r = 0, k = 0;
int main() {
    scanf("%d", &n);
    while (n > 1) {
        k += 6;
        n -= k;
        r++;
    }
    printf("%d\n", r+1);
    return 0;
}
