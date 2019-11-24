#include <set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

int A[100][100], B[100][100], C[100][100];

int main()
{
#ifdef _DEBUG
    freopen("2740.in", "r", stdin);
#endif

    memset(C, 0, sizeof(C));

    int R1, C1, R2, C2;
    cin >> R1 >> C1;
    for (int r = 0; r < R1; r++)
    for (int c = 0; c < C1; c++)
        cin >> A[r][c];

    cin >> R2 >> C2;
    for (int r = 0; r < R2; r++)
    for (int c = 0; c < C2; c++)
        cin >> B[r][c];

    for (int r = 0; r < R1; r++)
    for (int c = 0; c < C2; c++)
    for (int m = 0; m < C1; m++)
        C[r][c] += A[r][m] * B[m][c];

    for (int r = 0; r < R1; r++)
    for (int c = 0; c < C2; c++)
        printf("%d%c", C[r][c], " \n"[c + 1 == C2]);

    return 0;
}
