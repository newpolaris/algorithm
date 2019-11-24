#include <cstdio>
#include <cstdint>
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int64_t r = 0;
    for (int i = 1; i <= n; i++)
        r = r + (k % i);
    printf("%d\n", int(r));
    return 0;
}

/*
5 - 3
r = 0;
r = 0 + (3 % 1) = 0; - 1
r = 0 + (3 % 2) = 1; - 2
r = 1 + (3 % 3) = 1; - 3
r = 1 + (3 % 4) = 4; - 4

r = r*3 + (k % 1) + (k % 2) + (k % 3)

6 % 1 = 0
6 % 2 = 0
6 % 3 = 0
6 % 4 = 2
6 % 5 = 1
6 % 6 = 0
6 % 7 = 6

5 % 1 = 0
5 % 2 = 1
5 % 3 = 2
5 % 4 = 1

10 % 1 = 0
0
1
2
0
4
3
2
1


*/
