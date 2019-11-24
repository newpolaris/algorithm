#include <cstdio>
#include <cstdint>
int64_t a, b;
int main() {
    scanf("%lld %lld", &a, &b);
    while (a) {
        a = a % b;
        b = a;
    }
    return 0;
}

9 % 6 = 3 ~ 1
6 % 3 = 0 ~ 2
