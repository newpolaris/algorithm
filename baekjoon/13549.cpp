#include <cstdio>
#include <cstring>
#include <cstdlib>

constexpr int l = 100'000;
int a, b, c[l+100], k = 0, loop = 500;
int main() {
    scanf("%d %d", &a, &b);
    if (a > b) { 
        printf("%d\n", a - b);
        return 0;
    }
    memset(c, -1, sizeof(c));
    c[a] = 0;
    while (loop--) {
        for (int i = l; i >= 0; i--) {
            if (c[i] == k && i > 0) {
                for (int q = i*2; q <= 100'000; q *= 2) {
                    if (c[q] == -1)
                        c[q] = k;
                }
            }
        }
        if (c[b] >= 0)
            break;
        for (int i = l; i >= 0; i--) {
            if (c[i] == k) {
                if (c[i+1] == -1)
                    c[i+1] = k + 1;
                if (i > 1 && c[i-1] == -1)
                    c[i-1] = k + 1;
            }
        }
        k++;
    }
    printf("%d\n", k);
    return 0;
}
