#include <cstdio>
#include <algorithm>
int a, b, c;
int main() {
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", std::max(b - a, c - b) - 1);
    return 0;
}
