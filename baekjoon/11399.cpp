#include <cstdio>
#include <algorithm>

int n, c = 0, s = 0, k[1'001];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &k[i]);
    std::sort(k, k+n);
    for (int i = 0; i < n; i++) {
        c += s + k[i];
        s = s + k[i];
    }
    printf("%d\n", c);
    return 0;
}
