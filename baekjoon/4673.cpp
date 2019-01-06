#include <cstdio>
bool generator[10'001];
int next(int k) {
    return k + (k % 10) + (k / 10) % 10 + (k / 100) % 10 + (k / 1000) % 10;
}

int main() {
    for (int i = 1; i <= 10'000; i++) {
        if (generator[i]) continue;
        int k = i;
        while (k < 10'000) {
            k = next(k);
            generator[k] = true;
        } 
    }
    for (int i = 1; i <= 10'000; i++)
        if (!generator[i])
            printf("%d\n", i);
    return 0;
}
