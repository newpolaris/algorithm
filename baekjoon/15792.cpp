#include <cstdio>
int main() {
    int a, b, c = 1500;
    scanf("%d %d", &a, &b);
    printf("%d.", a/b);
    a -= b*(a/b);
    while (a != 0 && c > 0) {
        a *= 10;
        printf("%d", a/b);
        a = a - b*(a/b);
        c--;
    }
}
