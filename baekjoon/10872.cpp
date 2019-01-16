#include <cstdio>
int p(int k) {
    if (k <= 1) return 1;
    return p(k-1) * k;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", p(n));
    return 0;
}
