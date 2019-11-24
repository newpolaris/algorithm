#include <cstdio>
#include <cstring>
#include <cstdint>

const int64_t max = 400'000;
int era[max];

int main() {
    memset(era, 0, sizeof(era));

    for (int64_t i = 2; i < max; i++)
        for (int64_t k = i*i; k < max; k+= i)
            era[k] = 1;
    do {
        int n;
        scanf("%d", &n);
        if (n == 0) break;
        int cnt = 0;
        for (int i = n+1; i <= 2*n; i++)
            if (era[i] == 0) 
                cnt++;
        printf("%d\n", cnt);
    } while (true);
    return 0;
}
