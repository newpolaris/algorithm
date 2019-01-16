#include <cstdio>
/*
 * DP로 풀음.
 * 최대치 *2 범위를 포함하기 위해 200'000 배열 선언
 * 양수일 경우 log2(100'000) 은 적은 수 이기에
 * 전 범위 증가해도 시간내 처리 가능할 거라 생각
 */

constexpr int l = 200'000;
int a, b, c[l+1], k = 1;
int main() {
    scanf("%d %d", &a, &b);
    c[a] = 1;
    if (a > b) { 
        printf("%d\n", a - b);
        return 0;
    }

    while (true) {
        if (c[b] > 0) 
            break;
        for (int i = l; i >= 0; i--) {
            // 바로 앞에서 (i+1), (i-1) 한 수를 처리하지 않기 위해 index 저장
            if (c[i] == k) {
                if (c[i+1] <= k - 1)
                    c[i+1] = k + 1;
                if (i > 1 && c[i-1] <= k - 1)
                    c[i-1] = k + 1;
                if (i <= 100'000 && c[i*2] <= k - 1)
                    c[i*2] = k + 1;
            }
        }
        k++;
    }
    printf("%d\n", k-1);
    return 0;
}
