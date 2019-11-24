#include <cstdio>
#include <algorithm>
#include <cstring>
char ch[256];
int num[10];
int main() {
    scanf("%s", ch);
    for (int i = 0; ch[i]; i++)
        num[ch[i] - '0']++;
    num[6] += num[9];
    num[6] = (num[6]+1)/2;
    printf("%d\n", *std::max_element(num, num+8));
    return 0;
}
