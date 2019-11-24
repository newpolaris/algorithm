#include <cstdio>
#include <cstring>
using namespace std;
int t, n;
char ch[256];
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %s", &n, ch);
        for (int i = 0; i < strlen(ch); i++) {
            for (int k = 0; k < n; k++)
                printf("%c", ch[i]);
        }
        printf("\n");
    }
    return 0;
}
