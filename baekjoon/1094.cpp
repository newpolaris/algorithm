#include <cstdio>
#include <queue>
int x;
int main() {
    scanf("%d", &x);
    std::priority_queue<int> q;
    int s = 64;
    q.push(-64);
    while (s != x) {
        int t = q.top();
        q.pop();
        t /= 2;
        q.push(t);
        if (x <= s + t)
            s += t;
        else
            q.push(t);
    }
    printf("%ld\n", q.size());
    return 0;
}
