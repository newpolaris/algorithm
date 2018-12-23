#include <cstdio>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int cache[1001];
    memset(cache, -1, sizeof(cache));

    cache[1] = 1;
    cache[2] = 3;
    for (int i = 3; i <= 1000; i++)
        cache[i] = (cache[i-1] + 2*cache[i-2]) % 10'007;
    printf("%d\n", cache[n]);
    return 0;
}
