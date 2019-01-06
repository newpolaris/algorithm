#include <iostream>
#include <deque>
#include <cstdio>
#include <cstring>
int n, k;
char cmd[255];
std::deque<int> de;
int main() {
#ifdef _DEBUG
    freopen("10866.in", "r", stdin);
#endif
    scanf("%d", &n);
    while (n--) {
        scanf("%s", cmd);
        if (strstr(cmd, "push_back")) {
            scanf("%d", &k);
            de.push_back(k);
        } else if (strstr(cmd, "push_front")) {
            scanf("%d", &k);
            de.push_front(k);
        } else if (strstr(cmd, "pop_front")) {
            k = -1;
            if (de.size() > 0) { 
                k = de.front();
                de.pop_front();
            }
            printf("%d\n", k);
        } else if (strstr(cmd, "pop_back")) {
            k = -1;
            if (de.size() > 0) { 
                k = de.back();
                de.pop_back();
            }
            printf("%d\n", k);
        } else if (strstr(cmd, "size")) {
            printf("%d\n", int(de.size()));
        } else if (strstr(cmd, "empty")) {
            k = (de.empty()) ? 1 : 0;
            printf("%d\n", k);
        } else if (strstr(cmd, "front")) {
            k = -1;
            if (de.size() > 0) k = de.front();
            printf("%d\n", k);
        } else if (strstr(cmd, "back")) {
            k = -1;
            if (de.size() > 0) k = de.back();
            printf("%d\n", k);
        }
    }
    return 0;
}
