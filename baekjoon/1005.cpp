#include <cstdio>
#include <vector>
#include <queue>
#include <cstdint>
#include <string.h>
// topological sorting
using namespace std;
vector<vector<int>> vt;
vector<int> que;
bool cycle = false;
int N, T, K, a, b, r, finish[1'001];
bool visited[1'001];
void dfs(int v) {
    visited[v] = true;
    for (auto i : vt[v]) {
        if (!visited[i])
            dfs(i);
        else if (!finish[i])
            cycle = true;
    }
    finish[v] = true;
    que.push_back(v);
}
int main() {
#ifdef _DEBUG
    freopen("1005.in", "r", stdin);
#endif
    scanf("%d", &T);
    while (T--) {
        vt.clear();
        memset(finish, 0, sizeof(finish));
        memset(visited, 0, sizeof(visited));
        scanf("%d %d", &N, &K);
        std::vector<int> D(N);
        for (auto &d : D) scanf("%d", &d);
        vt.resize(N+1);
        for (int k = 0; k < K; k++) {
            scanf("%d %d", &a, &b);
            vt[b].push_back(a);
        }
        scanf("%d", &r);
        dfs(r);
        std::vector<int> cost(N+1, 0);
        for (auto q : que) {
            int c = 0;
            for (auto e : vt[q])
                c = std::max(c, cost[e]);
            cost[q] = c + D[q-1];
        }
        printf("%d\n", cost[r]);
    }
    return 0;
}

