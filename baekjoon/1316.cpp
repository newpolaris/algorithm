#include <cstdio>
#include <cstring>
int n, cnt = 0;
char ch[256];
int alpha[256];
int main() {
    scanf("%d", &n);
    while (n--) {
        memset(alpha, -1, sizeof(alpha));
        scanf("%s", ch);
        for (int i = 0; i < strlen(ch); i++) {
            int & c = alpha[ch[i]];
            if (c >= 0 && i - c >= 2) 
                break;
            c = i;
            if (i == strlen(ch) - 1) 
                cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
