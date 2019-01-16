#include <cstdio>
#include <algorithm>
#include <vector>

int n;
char m[26][26];
int dfs(int r, int c) {
    int cnt = 0; 
    if (r < 0 || c < 0 || r >= n || c >= n) 
        return cnt;
    if (m[r][c] != '1')
        return cnt;
    cnt++;
    m[r][c] = '2';
    cnt += dfs(r-1, c+0);
    cnt += dfs(r+1, c+0);
    cnt += dfs(r+0, c-1);
    cnt += dfs(r+0, c+1);
    return cnt;
}

int main() {
#ifdef _DEBUG
    freopen("2667.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", m[i]);
    std::vector<int> q;
    for (int r = 0; r < n; r++)
    for (int c = 0; c < n; c++) {
        int k = dfs(r, c);
        if (k > 0)
            q.push_back(k);
    }
    printf("%ld\n", q.size());
    std::sort(q.begin(), q.end());
    for (int i = 0; i < q.size(); i++)
        printf("%d\n", q[i]);
    return 0;
}
