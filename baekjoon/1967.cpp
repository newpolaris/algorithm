#include <vector>
#include <cstdio>
#include <algorithm>
int n, a, b, w;
struct child { int c, w, d; };
std::vector<child> node[10'001];
int dfs(int p) {
    int maxL = 0;
    for (auto& c : node[p]) {
        c.d = dfs(c.c) + c.w;
        maxL = std::max(c.d, maxL);
    }
    return maxL;
}
int main() {
#ifdef _DEBUG
    freopen("1967.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &w);
        node[a-1].push_back({b-1, w});
    }
    dfs(0);
    int maxL = 0;
    for (auto& c : node) {
        if (c.size() == 2)
            maxL = std::max(maxL, c[0].d + c[1].d);
        else if (c.size() == 1)
            maxL = std::max(maxL, c[0].d);
    }
    printf("%d\n", maxL);
    return 0;
}
