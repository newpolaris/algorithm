#include <bits/stdc++.h>

using namespace std;

long long a[500100], sum, pre;
int n, k;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    for (int i = 0; i < n; i++)
        sum += a[i];
    sort(a, a + n);
    long long mn = a[0], mx = a[n - 1], kk = k;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] >= mx)
            continue;
        long long tmp = min(mx - a[i], kk / (n - i - 1));
        mx -= tmp;
        kk -= tmp * (n - i - 1);
    }
    kk = k;
    for (int i = 0; i <= n - 1; i ++) {
        if (a[i] <= mn)
            continue;
        long long tmp = min(a[i] - mn, kk / i);
        mn += tmp;
        kk -= tmp * i;
    }
    printf("%I64d\n", max(sum % n ? 1LL : 0LL, mx - mn));
}
