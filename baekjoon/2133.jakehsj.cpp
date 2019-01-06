// idea from jakehsj
// (n-0) = (n-2)*3 + 2*((n-4) + (n-6) + ... )
// (n-2) = (n-4)*3 + 2*((n-6) + (n-8) + ... )
// (n-2)를 (n-0) 뒤의 항과 비교하면, (n-4)가 3배가 된것 빼곤 들어맞는다 

#include <cstdio>
int n, a[31]={1,0,3,0};
int main() {
    scanf("%d",&n);
    for(int i = 4;i <= n; i++)
        a[i] = 4*a[i-2] - a[i-4];
    printf("%d", a[n]);
    return 0;
}
