#include <cstdio>
#include <cstring>

const int mod = 10'000;
int n, t, queue[mod];
int head = 0, len = 0;
char cmd[15];

int tail() {
    return (head + len) % mod - 1;
}

int front() {
    if (len <= 0)
        return -1;
    return queue[head];
}

int back() {
    if (len <= 0)
        return -1;
    return queue[tail()];
}

int size() {
    return len;
}

int empty() {
    return len <= 0 ? 1 : 0;
}

void push(int t) {
    len++;
    queue[tail()] = t;
}

int pop() {
    if (len <= 0) return -1;
    int t = queue[head];
    head = (head + 1) % mod;
    len--;
    return t;
}

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%s", cmd);
        if (strstr(cmd, "push")) {
            scanf("%d", &t);
            push(t);
        } else if (strstr(cmd, "pop")) {
            printf("%d\n", pop());
        } else if (strstr(cmd, "size")) {
            printf("%d\n", size());
        } else if (strstr(cmd, "empty")) {
            printf("%d\n", empty());
        } else if (strstr(cmd, "front")) {
            printf("%d\n", front());
        } else if (strstr(cmd, "back")) {
            printf("%d\n", back());
        } 
    }
    return 0;
}
