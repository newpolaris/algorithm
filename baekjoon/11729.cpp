#include <cstdio>

void solve(int n, int a, int b, int c)
{
    if (n == 0)
        return;

    solve(n-1, a, c, b);
    printf("%d %d\n", a, c);
    solve(n-1, b, a, c);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", (1 << n) - 1);
    solve(n, 1, 2, 3);
    return 0;
}
