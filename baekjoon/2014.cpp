#include <cstdio>
#include <queue>
#include <set>
#include <algorithm>
#include <cstdint>
#include <limits>

//  2, 3, 5, 7
//  2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 27

int a[105], k, n;
int main() {
#ifdef _DEBUG
    freopen("2014.in", "r", stdin);
#endif
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++)
        scanf("%d", &a[i]);
    std::priority_queue<int> q;
    std::vector<int> v;
    q.push(-1);
    for (int i = 0; i < 2*n; i++) {
        int b = q.top(); 
        v.push_back(-b);
        q.pop();
        for (int j = 0; j < k; j++) {
            int64_t k = int64_t(-b) * a[j];
            if (k < std::numeric_limits<int>::max())
                q.push(b * a[j]);
        }
    }
    std::sort(v.begin(), v.end());
    auto it = std::unique(v.begin(), v.end());
    v.erase(it, v.end());
    printf("%d\n", v[n]);
    return 0;
}
