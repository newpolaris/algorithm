#include <cstdio>
#include <cstring>
char chars[101];
int main() {
    scanf("%s", chars);
    for (int i = 0; i < strlen(chars); i++) {
        printf("%c", chars[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
}
