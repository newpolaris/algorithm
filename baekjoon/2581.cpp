#include <cstdio>
#include <queue>
#include <algorithm>

int m, n;
bool nonPrime[10'001];
int main() {
    nonPrime[1] = true; 
    scanf("%d %d", &m, &n);
    for (int i = 2; i <= n; i++) {
        for (int k = i*i; k <= n; k += i)
            nonPrime[k] = true;
    }
    int sum = 0, minv = -1;
    for (int k = m; k <= n; k++) {
        if (!nonPrime[k]) {
            sum += k;
            if (minv < 0)
                minv = k;
        }
    }
    if (minv == -1)
        printf("%d\n", -1);
    else
        printf("%d\n%d\n", sum, minv);
    return 0;
}
