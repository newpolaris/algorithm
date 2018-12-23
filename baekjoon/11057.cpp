#include <cstdio>
#include <algorithm>
using namespace std;
int n, cache[10];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < 10; i++)
        cache[i] = 10 - i;
    for (int k = 1; k < n; k++) {
        int cnt = 0;
        for (int i = 9; i >= 0; i--) {
            cnt = (cnt + cache[i]) % 10'007;
            cache[i] = cnt;
        }
    }
    printf("%d\n", cache[0]);
    return 0;
}


/*
0-9 = 10
1-9 = 9
2-9 = 8
  ...
8-9 = 2
9-9 = 1

9 9-9 = 1 = 1
8 8-9 = 2 + 1 = 3
7 7-9 = 3 + 2 + 1 = 6
0 0-9 = 10 + ... + ... + 1

9 9 9-9 = 1
8 8 8-9 = 3 + 1
7 7 7-9 = 6
*/
