#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>
int main() {
    int n, k, t;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &k);
        std::vector<int> l(k);
        for (auto& a : l) scanf("%d", &a);
        double s = std::accumulate(l.begin(), l.end(), 0);
        auto cnt = std::count_if(l.begin(), l.end(), [&](auto a) { return a > s/k; });
        printf("%2.3f%%\n", double(cnt)/k*100);
    }
}
