#include <cstdio>

int L, P, p, n = 5;
int main() {
    scanf("%d %d", &L, &P);
    while (n--) {
        scanf("%d", &p);
        printf("%d ", p - L*P);
    }
    return 0;
}
