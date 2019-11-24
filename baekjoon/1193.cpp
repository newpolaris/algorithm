#include <cstdio>
#include <algorithm>
int main() {
    int x, n = 0, a = 0;
    scanf("%d", &x);
    while (n + a < x) {
        n += a;
        a++;
    }
    int diag = a;
    int remain = x - n;
    int r = remain;
    int c = diag - remain + 1;
    if (diag % 2 != 0)
        std::swap(r, c);
    printf("%d/%d\n", r, c);
    return 0;
}
