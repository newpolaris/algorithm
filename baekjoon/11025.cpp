#include <cstdio>
using namespace std;

int josephus(int n, int k) 
{ 
    if (n == 1) 
        return 1; 
    else
        return (josephus(n - 1, k) + k-1) % n + 1; 
} 

int n, m, j = 1;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 2; i <= n; i++)
        j = (j + m - 1) % i + 1;
    printf("%d\n", j);
    return 0;
}

/*
j(1, k) = 1
...
j(n - t, k)       = (j(n - (t + 1), k) + k - 1) % (n - t) + 1
j(n - (t - 1), k) = (j(n - t, k) + k - 1)       % (n - (t - 1)) + 1
j(n - 1, k)       = (j(n - 2, k) + k - 1)       % (n - 1) + 1
j(n, k)           = (j(n - 1, k) + k - 1)       % n + 1
*/
