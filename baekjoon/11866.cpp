#include <cstdio>
#include <deque>
#include <numeric>
#include <vector>
using namespace std;
int main() {
    int n, m, k;
    scanf("%d %d", &n, &m);
    deque<int> que(n);
    iota(que.begin(), que.end(), 1);
    vector<int> t;
    while (!que.empty()) {
        for (int i = 0; i < m; i++) {
            k = que.front();
            que.pop_front();
            if (i == m - 1)
                t.push_back(k);
            else
                que.push_back(k);
        }
    }
    printf("<");
    char b[] = ">\n";
    for (int i = 0; i < n - 1; i++) 
        printf("%d, ", t[i]);
    printf("%d>\n", t[n-1]);
    return 0;
}
