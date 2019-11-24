#include <cstdio>
#include <algorithm>

int main()
{
    int n, t, a = 1, b = 1;
    scanf("%d", &n);
    while (n--) {
        a = (a + b) % 15746;
        std::swap(a, b);
    }
    printf("%d\n", a);

    return 0;
}
