#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
#ifdef _DEBUG
    freopen("12865.in", "r", stdin);
#endif
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> weight(n);
    vector<int> value(n);
    vector<int> cache(k+1);
    cache[0] = 0;
    for (int i = 0; i < n; i++)
        scanf("%d %d", &weight[i], &value[i]);
    for (int i = 0; i < n; i++) {
        for (int w = k; w > 0; w--) {
            int preW = w - weight[i];
            if (preW >= 0) {
                cache[w] = max(cache[w], cache[preW] + value[i]);
            }
        }
    }
    printf("%d\n", *max_element(cache.begin(), cache.end()));
    return 0;
}
