// P.54
#include <algorithm>
#include <stdio.h>

const int MAX_N = 5;
bool used[MAX_N];
int perm[MAX_N];

void clear()
{
    std::fill(used, used + MAX_N, 0);
    for (int i = 0; i < MAX_N; i++) 
        perm[i] = i + 1;
    // std::stoi(perm, perm + MAX_N);
}

// { 0, 1, 2, 3, 4, ... , n -1 }의 n! 가지를 생성
void permutation1(int pos, int n)
{
    if (pos == n)  {
        // perm 에 대한 조작
        for (int i = 0; i < n; i++)
        printf("%d%c", perm[i], " \n"[i == n-1]);
        return;
    }

    // perm의 pos를 0 ~ n-1 중 어느 것으로 할 지에 대한 루프
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            perm[pos] = i;
            // i를 사용했으므로 true를 설정
            used[i] = true;
            permutation1(pos + 1, n);
            // 플래그를 false로 설정
            used[i] = false;
        }
    }
    return;
}

int main()
{
    clear();
    permutation1(0, MAX_N);

    return 0;
}