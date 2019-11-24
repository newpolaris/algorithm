#include <cstdio>
using namespace std;
int main() {
    int n, l, r, x, y;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &l, &r);
        if (l == 1) {
            x = 1, y = 2;
        } else {
            x = l, y = l*2;
        }
        printf("%d %d\n", x, y);
    }
    return 0;
}
