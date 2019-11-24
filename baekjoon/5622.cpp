#include <cstdio>
char ch[256];
int s[] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
int main() {
    scanf("%s", ch);
    int c = 0;
    for (int i = 0; ch[i]; i++)
        c += s[ch[i] - 'A'];
    printf("%d\n", c);
    return 0;
}
