#include <cstdio>
#include <cstring>
#include <algorithm>
int n;
char a[256][256];
char tmp[256];
int cnt() {
    int c = 0;
    for (int i = 0; i < n; i++) {
        memcpy(tmp, a[i], 256);
        char* token = strtok(tmp, "X");
        while (token != nullptr) {
            if (strlen(token) >= 2)
                c++;
            token = strtok(nullptr, "X");
        }
    }
    return c;
}

int main() {
#ifdef _DEBUG
    freopen("1652.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", a[i]);
    int o = cnt();
    for (int r = 0; r < n; r++)
    for (int c = r + 1; c < n; c++)
        std::swap(a[r][c], a[c][r]);
    int p = cnt();
    printf("%d %d\n", o, p);
    return 0;
}
