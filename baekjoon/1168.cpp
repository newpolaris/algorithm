#include <cstdio>
#include <deque>
#include <numeric>
#include <vector>
using namespace std;
int main() {
    int n, m, k = 0;
    scanf("%d %d", &n, &m);
    vector<int> que(n);
    iota(que.begin(), que.end(), 1);
    vector<int> t;
    while (!que.empty()) {
        k = (k + m - 1) % que.size();
        auto it = que.begin() + k;
        t.push_back(*it);
        que.erase(it);
    }
    printf("<");
    char b[] = ">\n";
    for (int i = 0; i < n - 1; i++) 
        printf("%d, ", t[i]);
    printf("%d>\n", t[n-1]);
    return 0;
}
