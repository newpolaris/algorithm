#include <cstdio>
int n;
int main() {
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i <= 99) cnt++;
        else {
            int mid = (i%100)/10;
            if ((mid - i/100) == (i%10 - mid)) cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
