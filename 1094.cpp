#include <cstdio>
#include <queue>
int x;
int main() {
    scanf("%d", &x);
    std::priority_queue<int> q;
    int s = 64;
    q.push(-64);
    int cnt = 0;
    while (!q.empty()) {
        cnt++;
        int t = q.top();
        q.pop();
        t /= 2;
        q.push(t);
        if (x < s + t)
            s += t;
        else
            q.push(t);
        if (s == x) 
            break;
    }
    printf("%d\n", cnt);
    return 0;
}
